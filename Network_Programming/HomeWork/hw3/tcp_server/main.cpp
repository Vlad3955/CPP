#include "tcp_server.h"
const size_t buffer_size = 256;


int main(int argc, char const* argv[])
{

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <port>" << std::endl;
        return EXIT_FAILURE;
    }


    socket_wrapper::SocketWrapper sock_wrap;
    //const int port{ std::stoi(argv[1]) };
    addrinfo *res = nullptr;
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
        .ai_protocol = 0
    };

    int status = 0;

    if ((status = getaddrinfo(NULL, argv[1], &hints, &res)) != 0)
    {
        std::cerr << "getaddrinfo error: " << gai_strerror(status) << std::endl;
        return EXIT_FAILURE;
    }

    socket_wrapper::Socket sock = { res->ai_family, res->ai_socktype, res->ai_protocol };

    //socket_wrapper::Socket sock = { AF_INET, SOCK_DGRAM, IPPROTO_UDP };

    std::cout << "Starting TCP-server on the port " << std::stoi(argv[1]) << "...\n";

    if (!sock)
    {
        std::cerr << sock_wrap.get_last_error_string() << std::endl;
        return EXIT_FAILURE;
    }

    /*sockaddr_in addr =
    {
        .sin_family = PF_INET,
        .sin_port = htons(port),
    };

    addr.sin_addr.s_addr = INADDR_ANY;*/

    
    //UDPServer udpserver;
    

    //if (bind(sock, reinterpret_cast<const sockaddr*>(&addr), sizeof(addr)) != 0)
    //{
    //    std::cerr << sock_wrap.get_last_error_string() << std::endl;
    //    // Socket will be closed in the Socket destructor.
    //    return EXIT_FAILURE;
    //}

    if (bind(sock, res->ai_addr, res->ai_addrlen) != 0)
    {
        std::cerr << sock_wrap.get_last_error_string() << std::endl;
        // Socket will be closed in the Socket destructor.
        return EXIT_FAILURE;
    }

    listen(sock, 10);

    clients_addr_size = sizeof(clients_addr);
    socket_wrapper::Socket newSock = accept(sock, reinterpret_cast<sockaddr*>(&clients_addr), &clients_addr_size);

    char buffer[buffer_size] = {};

    while (true)
    {

        if (recv(sock, buffer, sizeof(buffer) - 1, 0) < 0)
        {
            std::cerr << sock_wrap.get_last_error_string() << std::endl;
            return EXIT_FAILURE;
        }
        std::cout << buffer << std::endl;
    }

    //udpserver.listenUDP(sock);


    return EXIT_SUCCESS;
}

