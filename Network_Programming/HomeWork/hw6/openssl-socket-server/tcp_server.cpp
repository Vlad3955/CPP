#include "tcp_server.h"


#if !defined(MAX_PATH)
#   define MAX_PATH (256)
#endif



// TCPserver
//==================================================================================
//==================================================================================


TCPserver::TCPserver(socket_wrapper::Socket&& client_sock) : client_sock_(std::move(client_sock)) {}

std::string TCPserver::get_request()
{
    std::array<char, MAX_PATH + 1> buffer;
    size_t recv_bytes = 0;
    const auto size = buffer.size() - 1;

    std::cout << "Reading user request..." << std::endl;
    while (true)
    {
        auto result = recv(client_sock_, &buffer[recv_bytes], size - recv_bytes, 0);

        if (!result) break;

        if (-1 == result)
        {
            if (need_to_repeat()) continue;
            throw std::logic_error("Socket reading error");
        }

        auto fragment_begin = buffer.begin() + recv_bytes;
        auto ret_iter = std::find_if(fragment_begin, fragment_begin + result,
            [](char sym) { return '\n' == sym || '\r' == sym;  });
        if (ret_iter != buffer.end())
        {
            *ret_iter = '\0';
            recv_bytes += std::distance(fragment_begin, ret_iter);
            break;
        }
        recv_bytes += result;
        if (size == recv_bytes) break;
    }

    buffer[recv_bytes] = '\0';

    auto result = std::string(buffer.begin(), buffer.begin() + recv_bytes);
    std::cout << "Request = \"" << result << "\"" << std::endl;

    return result;
}

bool TCPserver::send_buffer(const std::vector<char>& buffer)
{
    size_t transmit_bytes_count = 0;
    const auto size = buffer.size();

    while (transmit_bytes_count != size)
    {
        auto result = send(client_sock_, &(buffer.data()[0]) + transmit_bytes_count, size - transmit_bytes_count, 0);
        if (-1 == result)
        {
            if (need_to_repeat()) continue;
            return false;
        }

        transmit_bytes_count += result;
    }

    return true;
}

bool TCPserver::send_file(fs::path const& file_path)
{
    if (!(fs::exists(file_path) && fs::is_regular_file(file_path))) return false;

    std::vector<char> buffer(buffer_size);
    std::ifstream file_stream(file_path, std::ifstream::binary);

    if (!file_stream) return false;

    std::cout << "Sending file " << file_path << "..." << std::endl;
    while (file_stream)
    {
        file_stream.read(&buffer[0], buffer.size());
        if (!send_buffer(buffer)) return false;
    }

    return true;
}

void TCPserver::server_run()
{
    while (true)
    {
        std::cout << "Client tid = " << std::this_thread::get_id() << std::endl;
        
        process();
    }
}

std::optional<fs::path> TCPserver::recv_file_path()
{
    auto request_data = get_request();
    if (!request_data.size()) return std::nullopt;

    auto cur_path = fs::current_path().wstring();
    auto file_path = fs::weakly_canonical(request_data).wstring();

#if defined(_WIN32)
    std::transform(cur_path.begin(), cur_path.end(), cur_path.begin(),
        [](wchar_t c) { return std::towlower(c); }
    );
    std::transform(file_path.begin(), file_path.end(), file_path.begin(),
        [](wchar_t c) { return std::towlower(c); }
    );
#endif
    if (file_path.find(cur_path) == 0)
    {
        file_path = file_path.substr(cur_path.length());
    }

    return fs::weakly_canonical(cur_path + separ + file_path);
}



bool TCPserver::process()
{
    auto file_to_send = recv_file_path();
    bool result = false;

    if (std::nullopt != file_to_send)
    {
        std::cout << "Trying to send " << *file_to_send << "..." << std::endl;
        if (send_file(*file_to_send))
        {
            std::cout << "File was sent." << std::endl;
        }
        else
        {
            std::cerr << "File sending error!" << std::endl;
        }
        result = true;
    }

    return result;
}

TCPserver::~TCPserver() {}



// Connector
//==================================================================================
//==================================================================================

Connector::Connector() {}

socket_wrapper::Socket Connector::connect_to_client(unsigned short port)
{
    socket_wrapper::SocketWrapper sock_wrap_;

    sockaddr_storage clients_addr = { 0 };
    socklen_t clients_addr_size;
    const int flag = 1;

    addrinfo hints =
    {
        .ai_flags = AI_PASSIVE,
        .ai_family = AF_INET,
        // TCP stream-sockets.
        .ai_socktype = SOCK_STREAM,
        // Any protocol.
        .ai_protocol = IPPROTO_TCP
    };

    addrinfo* s_i = nullptr;
    int status = 0;

    if ((status = getaddrinfo(NULL, std::to_string(port).c_str(), &hints, &s_i)) != 0)
    {
        std::string msg{ "getaddrinfo error: " };
        msg += gai_strerror(status);
        std::cout << msg;
        //throw std::runtime_error(msg);
        exit(EXIT_FAILURE);
    }

    std::unique_ptr<addrinfo, decltype(&freeaddrinfo)> servinfo{ s_i, freeaddrinfo };

    while (true)
    {
        for (auto const* s = servinfo.get(); s != nullptr; s = s->ai_next)
        {

            assert(s->ai_family == s->ai_addr->sa_family);
            if (AF_INET == s->ai_family)
            {
                char ip[INET_ADDRSTRLEN];

                sockaddr_in* const sin = reinterpret_cast<sockaddr_in* const>(s->ai_addr);

                sin->sin_family = AF_INET;
                sin->sin_port = htons(port);
                //sin->sin_addr.s_addr = INADDR_ANY;
                inet_pton(AF_INET, "192.168.100.9", &sin->sin_addr);

                socket_wrapper::Socket s = { AF_INET, SOCK_STREAM, IPPROTO_TCP };

                // Allow reuse of port.
                if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&flag), sizeof(flag)) < 0)
                {
                    std::cout << "Set SO_REUSEADDR error" << std::endl;
                    exit(EXIT_FAILURE);
                }

                if ((bind(s, reinterpret_cast<const sockaddr*>(sin), sizeof(sockaddr_in))) != 0)
                {
                    std::cerr << sock_wrap_.get_last_error_string() << std::endl;
                    std::cerr << "bind error" << std::endl;
                    exit(EXIT_FAILURE);
                }

                if ((listen(s, 10)) == -1)
                {
                    std::cerr << "sever: listen\n";
                    exit(EXIT_FAILURE);
                }


                std::cout << "Trying IP Address: " << inet_ntop(AF_INET, &sin->sin_addr.s_addr, ip, INET_ADDRSTRLEN) << std::endl;
                clients_addr_size = sizeof(clients_addr);

                socket_wrapper::Socket newSock = accept(s, reinterpret_cast<sockaddr*>(&clients_addr), &clients_addr_size);
                if (!newSock)
                {
                    std::cerr << sock_wrap_.get_last_error_string() << std::endl;
                    std::cout << "accept error";
                    exit(EXIT_FAILURE);
                }
                s.close();
                return newSock;
            }
            else if (AF_INET6 == s->ai_family)
            {
                char ip6[INET6_ADDRSTRLEN];

                sockaddr_in6* const sin = reinterpret_cast<sockaddr_in6* const>(s->ai_addr);

                sin->sin6_family = AF_INET6;
                sin->sin6_port = htons(port);
                sin->sin6_addr = in6addr_any;
                //inet_pton(AF_INET6, "", &sin->sin6_addr);

                socket_wrapper::Socket s = { AF_INET6, SOCK_STREAM, IPPROTO_TCP };

                // Allow reuse of port.
                if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&flag), sizeof(flag)) < 0)
                {
                    std::cout << "Set SO_REUSEADDR error" << std::endl;
                    exit(EXIT_FAILURE);
                }

                if ((bind(s, reinterpret_cast<const sockaddr*>(sin), sizeof(sockaddr_in6))) != 0)
                {
                    std::cerr << sock_wrap_.get_last_error_string() << std::endl;
                    std::cerr << "bind error" << std::endl;
                    exit(EXIT_FAILURE);
                }

                if ((listen(s, 10)) == -1)
                {
                    std::cerr << "sever: listen\n";
                    exit(EXIT_FAILURE);
                }

                std::cout << "Trying IPv6 Address: " << inet_ntop(AF_INET6, &sin->sin6_addr, ip6, INET6_ADDRSTRLEN) << std::endl;
                clients_addr_size = sizeof(clients_addr);

                socket_wrapper::Socket newSock = accept(s, reinterpret_cast<sockaddr*>(&clients_addr), &clients_addr_size);
                if (!newSock)
                {
                    std::cerr << sock_wrap_.get_last_error_string() << std::endl;
                    std::cout << "accept error";
                    exit(EXIT_FAILURE);
                }
                s.close();
                return newSock;
            }
        }  // for
    }  // while
}

Connector::~Connector() {}