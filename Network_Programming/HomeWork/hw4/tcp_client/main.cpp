#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <filesystem>
#include <fstream>

#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>


namespace fs = std::filesystem;

// Trim from end (in place).
static inline std::string& rtrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) { return !std::isspace(c); }).base());
    return s;
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
    auto cur_path = fs::current_path().wstring();


    std::cout << "Starting TCP-client on the port " << port << "...\n";


    addrinfo hints =
    {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
        .ai_protocol = IPPROTO_TCP
    };

    addrinfo* s_i = nullptr;
    int status = 0;

    if ((status = getaddrinfo(NULL, std::to_string(port).c_str(), &hints, &s_i)) != 0)
    {
        std::string msg{ "getaddrinfo error: " };
        msg += gai_strerror(status);
        std::cout << msg;
        exit(EXIT_FAILURE);
    }

    std::unique_ptr<addrinfo, decltype(&freeaddrinfo)> servinfo{ s_i, freeaddrinfo };

    for (auto const* s = servinfo.get(); s != nullptr; s = s->ai_next)
    {

        assert(s->ai_family == s->ai_addr->sa_family);
        if (AF_INET == s->ai_family)
        {
            char ip[INET_ADDRSTRLEN];

            sockaddr_in* const sin = reinterpret_cast<sockaddr_in* const>(s->ai_addr);
            sin->sin_family = AF_INET;
            sin->sin_port = htons(port);
            //sin->sin_addr.s_addr = INADDR_ANY; // not working 
            inet_pton(AF_INET, "192.168.100.9", &sin->sin_addr);

            socket_wrapper::Socket s = { AF_INET, SOCK_STREAM, IPPROTO_TCP };

            if (!s)
            {
                std::cout << "socket error" << std::endl;
                exit(EXIT_FAILURE);
            }

            if (connect(s, reinterpret_cast<const sockaddr*>(sin), sizeof(sockaddr_in)))
            {
                std::cout << "Connect IPv4 error!" << std::endl;
                return EXIT_FAILURE;
            }

            while (true)
            {

                char message[256];
                printf("Enter message: ");
                std::cin.getline(message, 256);

                // send the message
                send(s, message, strlen(message), 0);


                std::vector<char> buffer(256);
                recv(s, &(buffer.data()[0]), buffer.size(), 0);

                if (!buffer.empty())
                {
                    std::fstream file;
                    file.open(message, std::ios_base::out | std::ios_base::binary);

                    if (file.is_open())
                    {
                        std::cout << "Received file!" << std::endl;
                        for (auto& b : buffer)
                        {
                            std::cout << b;
                        }
                        std::cout << std::endl;
                        file.write(&buffer[0], buffer.size());
                    }
                }
            }

        }
        else if (AF_INET6 == s->ai_family)
        {
            char ip6[INET6_ADDRSTRLEN];

            sockaddr_in6* const sin = reinterpret_cast<sockaddr_in6* const>(s->ai_addr);

            sin->sin6_family = AF_INET6;
            sin->sin6_port = htons(port);
            //sin->sin6_addr = in6addr_any; // not working 
            inet_pton(AF_INET6, "", &sin->sin6_addr);

            socket_wrapper::Socket s = { AF_INET6, SOCK_STREAM, IPPROTO_TCP };

            if (!s)
            {
                std::cout << "Socket error!" << std::endl;
                exit(EXIT_FAILURE);
            }

            if (connect(s, reinterpret_cast<const sockaddr*>(sin), sizeof(sockaddr_in6)) < 0)
            {
                std::cout << "Connect IPv6 error!" << std::endl;
                return EXIT_FAILURE;
            }

            

            while (true)
            {

                char message[256];
                printf("Enter message: ");
                std::cin.getline(message, 256);

                // send the message
                send(s, message, strlen(message), 0);


                std::vector<char> buffer(256);
                recv(s, &(buffer.data()[0]), buffer.size(), 0);

                if (!buffer.empty())
                {
                    std::fstream file;
                    file.open(message, std::ios_base::out | std::ios_base::binary);

                    if (file.is_open())
                    {
                        std::cout << "Received file!" << std::endl;
                        for (auto& b : buffer)
                        {
                            std::cout << b;
                        }
                        std::cout << std::endl;
                        file.write(&buffer[0], buffer.size());
                    }
                }
            }
        }
    }  // for

    return EXIT_SUCCESS;
}