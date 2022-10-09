#include "uclient.h"

#define SERVER "localhost"  // or "localhost" - ip address of UDP server
#define BUFLEN 512  // max length of answer


int main(int argc, char const* argv[])
{
    sockaddr_in server;

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <port>" << std::endl;
        return EXIT_FAILURE;
    }


    socket_wrapper::SocketWrapper sock_wrap;
    const int port{ std::stoi(argv[1]) };

    socket_wrapper::Socket sock = { AF_INET, SOCK_DGRAM, IPPROTO_UDP };

    std::cout << "Starting echo server on the port " << port << "...\n";

    if (!sock)
    {
        std::cerr << sock_wrap.get_last_error_string() << std::endl;
        return EXIT_FAILURE;
    }

    memset((char*)&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.S_un.S_addr = inet_addr(SERVER);

    while (true)
    {
        //// Read content into buffer from an incoming client.
        //recv_len = recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
        //    reinterpret_cast<sockaddr*>(&client_address),
        //    &client_address_len);



        //int x = 0;
        //if (recv_len > 0)
        //{
        //    buffer[recv_len] = '\0';
        //    std::cout
        //        << "Client with address: "
        //        << inet_ntop(AF_INET, &client_address.sin_addr, client_address_buf, sizeof(client_address_buf) / sizeof(client_address_buf[0]))
        //        << ":" << ntohs(client_address.sin_port)
        //        << " and host name: ";
        //    if (x = getnameinfo(reinterpret_cast<sockaddr*>(&client_address), client_address_len,
        //        hbuf, sizeof(hbuf), nullptr, 0, NI_NAMEREQD) != 0)
        //    {
        //        std::cerr << "could not resolve hostname" << std::endl;
        //    }
        //    else
        //    {
        //        std::cout << "host" << hbuf << std::endl;
        //    }
        //    std::cout << " sent datagram "
        //        << "[length = "
        //        << recv_len
        //        << "]:\n'''\n"
        //        << buffer
        //        << "\n'''"
        //        << std::endl;
        //    std::string command_string = { buffer, 0, len };
        //    rtrim(command_string);
        //    if ("exit" == command_string)
        //    {
        //        std::cout << "See you!" << std::endl;
        //        run = false;
        //    }

        //    // send(sock, &buf, readden, 0);

        //    // Send same content back to the client ("echo").
        //    sendto(sock, buffer, recv_len, 0, reinterpret_cast<const sockaddr*>(&client_address),
        //        client_address_len);
        //}


        char message[BUFLEN];
        printf("Enter message: ");
        std::cin.getline(message, BUFLEN);

        // send the message
        sendto(sock, message, strlen(message), 0, (sockaddr*)&server, sizeof(sockaddr_in));


        // receive a reply and print it
        // clear the answer by filling null, it might have previously received data
        char answer[BUFLEN] = {};

        // try to receive some data, this is a blocking call
        int slen = sizeof(sockaddr_in);
        int answer_length;
        answer_length = recvfrom(sock, answer, BUFLEN, 0, (sockaddr*)&server, &slen);
        if (answer_length > 0)
        {
            std::cout << answer << "\n";
        }



        std::cout << std::endl;
    }


    
    /*UDPClient udpclient;
    
    udpclient.SendUDP(sock);*/

    return EXIT_SUCCESS;
}

