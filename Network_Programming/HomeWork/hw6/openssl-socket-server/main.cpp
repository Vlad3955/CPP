#include "tcp_server.h"
#include "connector.h"





const auto buf_size = 256;


bool recv_packet(SSL *ssl)
{
    char buf[buf_size];
    int len = 0;

    do
    {
        len = SSL_read(ssl, buf, buf_size - 1);
        buf[len] = 0;
        std::cout << buf << std::endl;
    }
    while (len > 0);

    if (len < 0)
    {
        switch (SSL_get_error(ssl, len))
        {
            // Not an error.
            case SSL_ERROR_WANT_READ:
            case SSL_ERROR_WANT_WRITE:
                return true;
            break;
            case SSL_ERROR_ZERO_RETURN:
            case SSL_ERROR_SYSCALL:
            case SSL_ERROR_SSL:
                return false;
        }
    }

    return true;
}


bool send_packet(const std::string &buf, SSL *ssl)
{
    int len = SSL_write(ssl, buf.c_str(), buf.size());
    if (len < 0)
    {
        int err = SSL_get_error(ssl, len);
        switch (err)
        {
            case SSL_ERROR_WANT_WRITE:
            case SSL_ERROR_WANT_READ:
                return true;
            break;
            case SSL_ERROR_ZERO_RETURN:
            case SSL_ERROR_SYSCALL:
            case SSL_ERROR_SSL:
            default:
                return false;
        }
    }

    return false;
}


void log_ssl()
{
    for (int err = ERR_get_error(); err; err = ERR_get_error())
    {
        char *str = ERR_error_string(err, 0);
        if (!str) return;
        std::cerr << str << std::endl;
    }
}


int main(int argc, const char * const argv[])
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
    // TCPserver tcpserver(std::move(sock));
    // tcpserver.server_run();



    SSL *ssl = nullptr;

    SSL_library_init();
    SSLeay_add_ssl_algorithms();
    SSL_load_error_strings();

    const SSL_METHOD *meth = TLS_server_method();
    SSL_CTX *ctx = SSL_CTX_new(meth);
    ssl = SSL_new(ctx);

    fs::path path_cert = fs::current_path() / "../certificates" / "server.pem";
    fs::path path_key  = fs::current_path() / "../certificates" / "key.pem";

    std::string serv_pem = path_cert.string();
    std::string key_pem = path_key.string();

    //Загрузка сертификата.
    if (SSL_CTX_use_certificate_file(ctx, serv_pem.c_str(), SSL_FILETYPE_PEM) <= 0)
    {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Загрузка ключа.
    if (SSL_CTX_use_PrivateKey_file(ctx, key_pem.c_str(), SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // //Загрузка сертификата.
    // if (SSL_CTX_use_certificate_file(ctx, "/home/vlad/CPP/Pract/HomeWork/build/certificates/server.pem", SSL_FILETYPE_PEM) <= 0)
    // {
    //     ERR_print_errors_fp(stderr);
    //     exit(EXIT_FAILURE);
    // }

    // // Загрузка ключа.
    // if (SSL_CTX_use_PrivateKey_file(ctx, "/home/vlad/CPP/Pract/HomeWork/build/certificates/key.pem", SSL_FILETYPE_PEM) <= 0 )
    // {
    //     ERR_print_errors_fp(stderr);
    //     exit(EXIT_FAILURE);
    // }


    // verify private key
    if ( !SSL_CTX_check_private_key(ctx) )
    {
        ERR_print_errors_fp(stderr);
        return false;
    }


    

    if (!ssl)
    {
        std::cerr << "Error creating SSL." << std::endl;
        log_ssl();
        return EXIT_FAILURE;
    }

    SSL_set_fd(ssl, sock);

     

    int err = SSL_accept(ssl);
    if (err <= 0)
    {
        std::cerr << "Error creating SSL connection.  err = " << err << std::endl;
        log_ssl();
        return EXIT_FAILURE;
    }

    

    std::cout << "SSL connection using " << SSL_get_cipher(ssl) << std::endl;
    
    
   


    recv_packet(ssl);
    //std::string request = {"GET / HTTP/1.1\r\n\r\n"};
    std::string request = {"brm-brm"};
    send_packet(request, ssl);
    

    SSL_shutdown(ssl);

    return EXIT_SUCCESS;
}

