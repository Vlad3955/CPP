#include "tcp_server.h"



socket_wrapper::Socket connect_to_client(const std::string& host_name, unsigned short port)
//socket_wrapper::Socket connect_to_client(unsigned short port)
{
    socket_wrapper::SocketWrapper sock_wrap_;

    sockaddr_storage clients_addr = { 0 };
    socklen_t clients_addr_size;


    addrinfo hints =
    {
        .ai_flags = AI_PASSIVE,
        // Неважно, IPv4 или IPv6.
        .ai_family = AF_UNSPEC,
        // TCP stream-sockets.
        .ai_socktype = SOCK_STREAM,
        // Any protocol.
        .ai_protocol = IPPROTO_TCP
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

                std::cout << "Trying IP Address: " << inet_ntop(AF_INET, &addr, ip, INET_ADDRSTRLEN) << std::endl;
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


                socket_wrapper::Socket s = { AF_INET6, SOCK_STREAM, IPPROTO_TCP };

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

                std::cout << "Trying IPv6 Address: " << inet_ntop(AF_INET6, &(sin->sin6_addr), ip6, INET6_ADDRSTRLEN) << std::endl;
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
    int recv_len;


    std::cout << "Starting TCP-server on the port " << port << "...\n";

    socket_wrapper::Socket sock = connect_to_client("192.168.4.73", port);
    //socket_wrapper::Socket sock = connect_to_client(port);


    char buffer[256] = {};

    while (true)
    {
        recv_len = recv(sock, buffer, sizeof(buffer) - 1, 0);
        buffer[recv_len] = '\0';
        if (recv_len > 0)
        {
            std::cout << "Bytes received: \n" << recv_len << std::endl;
            std::cout << buffer << std::endl;
        }

        send(sock, buffer, recv_len, 0);

    }

    return EXIT_SUCCESS;
}




//void* get_in_addr(sockaddr* sa)
//{
//    if (sa->sa_family == AF_INET)
//    {
//        return &reinterpret_cast<sockaddr_in*>(sa)->sin_addr;
//    }
//    return &reinterpret_cast<sockaddr_in6*>(sa)->sin6_addr;
//}
//
//
//
//int main(int argc, char const* argv[])
////int main()
//{
//
//    if (argc != 2)
//    {
//        std::cout << "Usage: " << argv[0] << " <port>" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    const int port{ std::stoi(argv[1]) };
//    //const int port{ std::stoi("15234")};
//    socket_wrapper::SocketWrapper sock_wrap;
//    int so, recv_len;
//    addrinfo* res = nullptr, * p = nullptr;
//    sockaddr_storage clients_addr = { 0 };
//    socklen_t clients_addr_size = 0;
//
//
//    addrinfo hints =
//    {
//        .ai_flags = AI_PASSIVE,
//        // Неважно, IPv4 или IPv6.
//        .ai_family = AF_UNSPEC,
//        // TCP stream-sockets.
//        .ai_socktype = SOCK_STREAM,
//        // Any protocol.
//        .ai_protocol = 0
//    };
//
//    int status = 0;
//
//    if ((status = getaddrinfo(NULL, argv[1], &hints, &res)) != 0)
//    {
//        std::cerr << "getaddrinfo error: " << gai_strerror(status) << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    
//    for (p = res; p != NULL; p->ai_next)
//    {
//        socket_wrapper::Socket sock = { p->ai_family, p->ai_socktype, p->ai_protocol };
//
//        if ((so = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
//        {
//            std::cerr << sock_wrap.get_last_error_string() << std::endl;
//            continue;
//        }
//
//        if (bind(so, p->ai_addr, p->ai_addrlen) != 0)
//        {
//            closesocket(so);
//            std::cerr << sock_wrap.get_last_error_string() << std::endl;
//            continue;
//        }
//        
//        break;
//      
//    }
//
//
//
//    if (p == NULL)
//    {
//        std::cerr << "sever: faild to bind\n";
//        return 2;
//    }
//
//    freeaddrinfo(res);
//
//    socket_wrapper::Socket sock = so;
//    closesocket(so);
//
//
//    if (listen(sock, 10) == -1)
//    {
//        std::cerr << "sever: listen\n";
//        //closesocket(sock);
//        return EXIT_FAILURE;
//    }
//
//    
//
//    std::cout << "Starting TCP-server on the port " << port << "...\n";
//
//    
//
//    char buffer[256] = {};
//    char s[INET6_ADDRSTRLEN];
//
//    while (true)
//    {
//        socket_wrapper::Socket newSock = accept(sock, reinterpret_cast<sockaddr*>(&clients_addr), &clients_addr_size);
//        
//        clients_addr_size = sizeof(clients_addr);
//        if (!newSock)
//        {
//            std::cerr << sock_wrap.get_last_error_string() << std::endl;
//            continue;
//        }
//        
//
//        inet_ntop(clients_addr.ss_family, get_in_addr(reinterpret_cast<sockaddr*>(&clients_addr)), s, sizeof(s));
//        std::cout << "server got connection from " << s;
//
//        
//
//       /* if (recv(newSock, buffer, sizeof(buffer) - 1, 0) < 0)
//        {
//            std::cerr << sock_wrap.get_last_error_string() << std::endl;
//            return EXIT_FAILURE;
//        }*/
//
//        recv_len = recv(newSock, buffer, sizeof(buffer) - 1, 0);
//        buffer[recv_len] = '/0';
//        if (recv_len > 0)
//        {
//            std::cout << "Bytes received: \n" << recv_len << std::endl;
//            std::cout << buffer << std::endl;
//        }
//        
//        send(newSock, buffer, recv_len, 0);
//    }
//
//
//    return EXIT_SUCCESS;
//}