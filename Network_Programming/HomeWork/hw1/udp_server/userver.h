#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>

// Trim from end (in place).
static inline std::string& rtrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) { return !std::isspace(c); }).base());
    return s;
}


class UDPServer
{
public:
	UDPServer();
    void listenUDP(socket_wrapper::Socket& sock);
	~UDPServer();
private:
    struct sockaddr_in client_address;
    socklen_t client_address_len;
    ssize_t recv_len;
};


