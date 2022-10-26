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
#include <array>
#include <optional>
#include <filesystem>
#include <thread>

#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>




//const auto clients_count = 10;
const auto buffer_size = 4096;
using namespace std::literals;
namespace fs = std::filesystem;

#if defined(_WIN32)
const wchar_t separ = fs::path::preferred_separator;
#else
const wchar_t separ = *reinterpret_cast<const wchar_t*>(&fs::path::preferred_separator);
#endif


// Trim from end (in place).
static inline std::string& rtrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) { return !std::isspace(c); }).base());
    return s;
}


class Connecter
{
public:
    Connecter();
    socket_wrapper::Socket connect_to_client(unsigned short port);
    ~Connecter();
private:

};


class TCPserver
{
public:
    TCPserver(socket_wrapper::Socket&& client_sock);
    TCPserver(const TCPserver&) = delete;
    TCPserver() = delete;
    std::string get_request();
    void server_run();
    bool send_file(fs::path const& file_path);
    bool send_buffer(const std::vector<char>& buffer);
    std::optional<fs::path> recv_file_path();
    bool process();
    ~TCPserver();
private:
    static bool need_to_repeat()
    {
        switch (errno)
        {
        case EINTR:
        case EAGAIN:
            // case EWOULDBLOCK: // EWOULDBLOCK == EINTR.
            return true;
        }

        return false;
    };
private:
    socket_wrapper::Socket client_sock_;
};










