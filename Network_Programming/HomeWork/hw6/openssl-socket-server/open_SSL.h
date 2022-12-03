#pragma once
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <cwctype>
#include <stdexcept>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <array>
#include <optional>
#include <filesystem>
#include <thread>
#include <vector>

#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>

namespace fs = std::filesystem;
const auto buf_size = 256;

extern "C"
{
#include <openssl/ssl.h>
#include <openssl/err.h>
}


class open_SSL
{
private:
  socket_wrapper::Socket client_sock_;
  const SSL_METHOD *meth {nullptr};
  SSL_CTX *ctx {nullptr};
  SSL *ssl = nullptr;
  
public:
    open_SSL(socket_wrapper::Socket&& client_sock);
    bool ssl_init();
    bool recv_packet(SSL *ssl);
    bool send_packet(const std::string &buf, SSL *ssl);
    void client_processing();
    void log_ssl();
    ~open_SSL();
};