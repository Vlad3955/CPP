#include "tcp_server.h"



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
    Connector connector;

    std::cout << "Starting TCP-server on the port " << port << "...\n";

    socket_wrapper::Socket sock = connector.connect_to_client(port);

    TCPserver tcpserver(std::move(sock));
    tcpserver.server_run();
    

    return EXIT_SUCCESS;
}