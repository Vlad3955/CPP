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


// const auto buffer_size = 4096;
// namespace fs = std::filesystem;

// #if !defined(MAX_PATH)
// #   define MAX_PATH (256)
// #endif

// #if defined(_WIN32)
// const wchar_t separ = fs::path::preferred_separator;
// #else
// const wchar_t separ = *reinterpret_cast<const wchar_t*>(&fs::path::preferred_separator);
// #endif

// // Trim from end (in place).
// static inline std::string& rtrim(std::string& s)
// {
//     s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) { return !std::isspace(c); }).base());
//     return s;
// }

// class File_Proccesing
// {
// private:
//     static bool need_to_repeat()
//     {
//         switch (errno)
//         {
//         case EINTR:
//         case EAGAIN:
//             // case EWOULDBLOCK: // EWOULDBLOCK == EINTR.
//             return true;
//         }

//         return false;
//     };
// private:
//     //socket_wrapper::Socket sock_;
// public:
//     File_Proccesing();
//     // File_Proccesing(const File_Proccesing&) = delete;
//     // File_Proccesing() = delete;
//     socket_wrapper::Socket get_sock(socket_wrapper::Socket&& sock);
//     std::string get_request();
//     bool send_file(fs::path const& file_path);
//     bool send_buffer(const std::vector<char>& buffer);
//     std::optional<fs::path> recv_file_path();
//     bool process();
//     ~File_Proccesing();
// };

// File_Proccesing::File_Proccesing() {}

// socket_wrapper::Socket get_sock(socket_wrapper::Socket&& sock)
// {
//     socket_wrapper::Socket sock_(std::move(sock));
//     return sock_;
// }

// std::string File_Proccesing::get_request()
// {
//     std::array<char, MAX_PATH + 1> buffer;
//     size_t recv_bytes = 0;
//     const auto size = buffer.size() - 1;

//     std::cout << "Reading user request..." << std::endl;
//     while (true)
//     {
//         auto result = recv(get_sock, &buffer[recv_bytes], size - recv_bytes, 0);

//         if (!result) break;

//         if (-1 == result)
//         {
//             if (need_to_repeat()) continue;
//             throw std::logic_error("Socket reading error");
//         }

//         auto fragment_begin = buffer.begin() + recv_bytes;
//         auto ret_iter = std::find_if(fragment_begin, fragment_begin + result,
//             [](char sym) { return '\n' == sym || '\r' == sym;  });
//         if (ret_iter != buffer.end())
//         {
//             *ret_iter = '\0';
//             recv_bytes += std::distance(fragment_begin, ret_iter);
//             break;
//         }
//         recv_bytes += result;
//         if (size == recv_bytes) break;
//     }

//     buffer[recv_bytes] = '\0';

//     auto result = std::string(buffer.begin(), buffer.begin() + recv_bytes);
//     std::cout << "Request = \"" << result << "\"" << std::endl;

//     return result;
// }

// bool File_Proccesing::send_buffer(const std::vector<char>& buffer)
// {
//     size_t transmit_bytes_count = 0;
//     const auto size = buffer.size();

//     while (transmit_bytes_count != size)
//     {
//         auto result = send(get_sock, &(buffer.data()[0]) + transmit_bytes_count, size - transmit_bytes_count, 0);
//         if (-1 == result)
//         {
//             if (need_to_repeat()) continue;
//             return false;
//         }

//         transmit_bytes_count += result;
//     }

//     return true;
// }

// bool File_Proccesing::send_file(fs::path const& file_path)
// {
//     if (!(fs::exists(file_path) && fs::is_regular_file(file_path))) return false;

//     std::vector<char> buffer(buffer_size);
//     std::ifstream file_stream(file_path, std::ifstream::binary);

//     if (!file_stream) return false;

//     std::cout << "Sending file " << file_path << "..." << std::endl;
//     while (file_stream)
//     {
//         file_stream.read(&buffer[0], buffer.size());
//         if (!send_buffer(buffer)) return false;
//     }

//     return true;
// }

// std::optional<fs::path> File_Proccesing::recv_file_path()
// {
//     auto request_data = get_request();
//     if (!request_data.size()) return std::nullopt;

//     auto cur_path = fs::current_path().wstring();
//     auto file_path = fs::weakly_canonical(request_data).wstring();

// #if defined(_WIN32)
//     std::transform(cur_path.begin(), cur_path.end(), cur_path.begin(),
//         [](wchar_t c) { return std::towlower(c); }
//     );
//     std::transform(file_path.begin(), file_path.end(), file_path.begin(),
//         [](wchar_t c) { return std::towlower(c); }
//     );
// #endif
//     if (file_path.find(cur_path) == 0)
//     {
//         file_path = file_path.substr(cur_path.length());
//     }

//     return fs::weakly_canonical(cur_path + separ + file_path);
// }

// bool File_Proccesing::process()
// {
//     auto file_to_send = recv_file_path();
//     bool result = false;

//     if (std::nullopt != file_to_send)
//     {
//         std::cout << "Trying to send " << *file_to_send << "..." << std::endl;
//         if (send_file(*file_to_send))
//         {
//             std::cout << "File was sent." << std::endl;
//         }
//         else
//         {
//             std::cerr << "File sending error!" << std::endl;
//         }
//         result = true;
//     }

//     return result;
// }

// File_Proccesing::~File_Proccesing() {}
