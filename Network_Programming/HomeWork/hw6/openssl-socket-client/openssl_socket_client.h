#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <filesystem>
#include <fstream>

#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>

extern "C"
{
#include <openssl/ssl.h>
#include <openssl/err.h>
}

const auto buffer_size = 256;

class Openssl_Socket_Client
{
public:
    Openssl_Socket_Client(/* args */);
    bool ssl_init();
    void srver_connect();
    ~Openssl_Socket_Client();

private:
    SSL *ssl = nullptr;
    const SSL_METHOD *meth{nullptr};
    SSL_CTX *ctx{nullptr};
};

Openssl_Socket_Client::Openssl_Socket_Client(/* args */)
{
}

bool Openssl_Socket_Client::ssl_init()
{
    SSL_library_init();
    SSLeay_add_ssl_algorithms();
    SSL_load_error_strings();

     const SSL_METHOD *meth = TLS_client_method();
      SSL_CTX *ctx = SSL_CTX_new(meth);

    if (!ssl)
    {
        std::cerr << "Error creating SSL." << std::endl;
        log_ssl();
        return EXIT_FAILURE;
    }
}

void Openssl_Socket_Client::srver_connect()
{
    ssl = SSL_new(ctx);

    if (!ssl)
    {
        std::cerr << "Error creating SSL." << std::endl;
        log_ssl();
        exit(-1);
    }

    SSL_set_fd(ssl, s);

    int err = SSL_connect(ssl);
    if (err <= 0)
    {
        std::cerr << "Error creating SSL connection.  err = " << err << std::endl;
        log_ssl();
        exit(-1);
    }
    std::cout << "SSL connection using " << SSL_get_cipher(ssl) << std::endl;

    

    while (true)
    {
        std::string message;
        printf("Enter message: ");
        std::getline(std::cin, message);

        // send the message
        send_packet(message, ssl);

        recv_packet(ssl, message);
    }
}

bool recv_packet(SSL *ssl, const std::string &message)
{
    int len = 0;
    std::vector<char> buffer(4096);
    len = SSL_read(ssl, &(buffer.data()[0]), buffer.size());

    if (len > 0)
    {
        buffer.resize(len);
        std::fstream file;
        file.open(message, std::ios_base::out | std::ios_base::binary);

        if (file.is_open())
        {
            std::cout << "Received file!" << std::endl;
            for (auto &b : buffer)
            {
                std::cout << b;
            }
            std::cout << std::endl;
            file.write(&buffer[0], buffer.size());
        }
    }

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
        if (!str)
            return;
        std::cerr << str << std::endl;
    }
}

Openssl_Socket_Client::~Openssl_Socket_Client()
{
    SSL_shutdown(ssl);
}
