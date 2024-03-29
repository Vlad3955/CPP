#include "userver.h"

UDPServer::UDPServer()
{
    client_address = { 0 };
    client_address_len = sizeof(sockaddr_in);
    recv_len = 0;
}


void UDPServer::listenUDP(socket_wrapper::Socket& sock)
{
    std::cout << "Running echo server(Enter 'exit' to exit)...\n" << std::endl;
    const int len = 256;
    char buffer[len];
    char client_address_buf[INET_ADDRSTRLEN];
    char hbuf[NI_MAXHOST];
    bool run = true;

    while (run)
    {
        // Read content into buffer from an incoming client.
        recv_len = recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
            reinterpret_cast<sockaddr*>(&client_address),
            &client_address_len);



        int x = 0;
        if (recv_len > 0)
        {
            buffer[recv_len] = '\0';
            std::cout
                << "Client with address: "
                << inet_ntop(AF_INET, &client_address.sin_addr, client_address_buf, sizeof(client_address_buf) / sizeof(client_address_buf[0]))
                << ":" << ntohs(client_address.sin_port)
                << " and host name: ";
            if (x = getnameinfo(reinterpret_cast<sockaddr*>(&client_address), client_address_len,
                hbuf, sizeof(hbuf), nullptr, 0, NI_NAMEREQD) != 0)
            {
                std::cerr << "could not resolve hostname" << std::endl;
            }
            else
            {
                std::cout << "host" << hbuf << std::endl;
            }
            std::cout << " sent datagram "
                << "[length = "
                << recv_len
                << "]:\n'''\n"
                << buffer
                << "\n'''"
                << std::endl;
            std::string command_string = { buffer, 0, len };
            rtrim(command_string);
            if ("exit" == command_string)
            {
                std::cout << "See you!" << std::endl;
                run = false;
            }

            // send(sock, &buf, readden, 0);

           // Send same content back to the client ("echo").
            sendto(sock, buffer, recv_len, 0, reinterpret_cast<const sockaddr*>(&client_address),
                client_address_len);
        }

        std::cout << std::endl;
    }
}

UDPServer::~UDPServer()
{
}



