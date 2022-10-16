#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>

#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>

socket_wrapper::Socket connect_to_server(const std::string& host_name, unsigned short port)
{
    socket_wrapper::SocketWrapper sock_wrap_;
    addrinfo hints =
    {
        .ai_flags = AI_PASSIVE,
        // Неважно, IPv4 или IPv6.
        .ai_family = AF_UNSPEC,
        // TCP stream-sockets.
        .ai_socktype = SOCK_STREAM,
        // Any protocol.
        .ai_protocol = 0
    };

    addrinfo* s_i = nullptr;
    int status = 0;

    if ((status = getaddrinfo(host_name.c_str(), std::to_string(port).c_str(), &hints, &s_i)) != 0)
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
                in_addr addr;
                addr.s_addr = *reinterpret_cast<const in_addr_t*>(&sin->sin_addr);

                sin->sin_family = AF_INET;
                sin->sin_port = htons(port);


                socket_wrapper::Socket s = { AF_INET, SOCK_STREAM, IPPROTO_TCP };

                if (connect(s, reinterpret_cast<const sockaddr*>(sin), sizeof(sockaddr_in)))
                {
                    std::cout << "Trying IP Address: " << inet_ntop(AF_INET, &addr, ip, INET_ADDRSTRLEN) << std::endl;
                    return s;
                }
                else
                {
                    std::cout << "Connect error";
                    return 1;
                }
            }
            else if (AF_INET6 == s->ai_family)
            {
                char ip6[INET6_ADDRSTRLEN];

                sockaddr_in6* const sin = reinterpret_cast<sockaddr_in6* const>(s->ai_addr);

                sin->sin6_family = AF_INET6;
                sin->sin6_port = htons(port);


                socket_wrapper::Socket s = { AF_INET6, SOCK_STREAM, IPPROTO_TCP };

                if (connect(s, reinterpret_cast<const sockaddr*>(sin), sizeof(sockaddr_in6)))
                {
                    std::cout << "Trying IPv6 Address: " << inet_ntop(AF_INET6, &(sin->sin6_addr), ip6, INET6_ADDRSTRLEN) << std::endl;
                    return s;
                }
                else
                {
                    std::cout << "Connect error";
                    return 1;
                }
            }
        }  // for
    }

    //throw std::runtime_error("Connection error: " + sock_wrap_.get_last_error_string());
}



int main(int argc, char const* argv[])
//int main()
{

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <port>" << std::endl;
        return EXIT_FAILURE;
    }

    const int port{ std::stoi(argv[1]) };
    //const int port{ std::stoi("15234")};
    socket_wrapper::SocketWrapper sock_wrap;


    std::cout << "Starting TCP-server on the port " << port << "...\n";

    socket_wrapper::Socket sock = connect_to_server("192.168.100.13", port);


    while (true)
    {
        
        char message[256];
        printf("Enter message: ");
        std::cin.getline(message, 256);

        // send the message
        send(sock, message, strlen(message), 0);


        // receive a reply and print it
        // clear the answer by filling null, it might have previously received data
        char answer[256] = {};

        // try to receive some data, this is a blocking call
        int answer_length;
        answer_length = recv(sock, answer, strlen(message), 0);
        if (answer_length > 0)
        {
            std::cout << answer << "\n";
        }

    }


    return EXIT_SUCCESS;
}

