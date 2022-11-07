#include <ctime>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <boost/system/error_code.hpp>
#include <boost/asio.hpp>


using boost::asio::ip::tcp;
const int echo_port = 1300;

std::string make_daytime_string()
{
    using namespace std; // time_t, time и ctime;
    time_t now = time(0);
    return ctime(&now);
}


// Указатель shared_ptr и enable_shared_from_this нужны для того,
// чтобы сохранить объект tcp_connection до завершения выполнения операции.
class TcpConnection : public std::enable_shared_from_this<TcpConnection>
{
public:
    typedef std::shared_ptr<TcpConnection> pointer;

    static pointer create(boost::asio::io_context& io_context)
    {
        return pointer(new TcpConnection(io_context));
    }

    tcp::socket& socket()
    {
        return socket_;
    }

    // В методе start(), вызывается asio::async_write(), отправляющий данные клиенту.
    // Здесь используется asio::async_write(), вместо ip::tcp::socket::async_write_some(), чтобы весь блок данных был гарантированно отправлен.
    void start()
    {
        // The data to be sent is stored in the class member message_ as we need to keep the data valid until the asynchronous operation is complete.
        message_ = make_daytime_string();
        auto s = shared_from_this();

        // Здесь вместо boost::bind используется std::bind, чтобы уменьшить число зависимостей от Boost.
        // Он не работает с плейсхолдерами из Boost.
        // В комментариях указаны альтернативные плейсхолдеры.
        boost::asio::async_write(socket_, boost::asio::buffer(message_),
            // handle_write() выполнит обработку запроса клиента.
            [s] (const boost::system::error_code& error, size_t bytes_transferred)
            {
                s->handle_write(error, bytes_transferred);
            }
    );
    }

private:
    TcpConnection(boost::asio::io_context& io_context)
        : socket_(io_context)
    {
    }

    void handle_write(const boost::system::error_code& /*error*/, size_t bytes_transferred)
    {
		std::cout << "Bytes transferred: " << bytes_transferred << std::endl;
    }

private:
    tcp::socket socket_;
    std::string message_;
};


class TcpServer
{
public:
    // В конструкторе инициализируется акцептор, начинается прослушивание TCP порта.
    TcpServer(boost::asio::io_context& io_context) :
        io_context_(io_context),
        acceptor_(io_context, tcp::endpoint(tcp::v4(), echo_port))
    {
        start_accept();
    }

private:
    // Метод start_accept() создаёт сокет и выполняет асинхронный `accept()`, при соединении.
    void start_accept()
    {
        TcpConnection::pointer new_connection = TcpConnection::create(io_context_);

        acceptor_.async_accept(new_connection->socket(),
            [this, new_connection] (const boost::system::error_code& error)
            {
                this->handle_accept(new_connection, error);
            }
        );
    }

    // Метод handle_accept() вызывается, когда асинхронный accept, инициированный в start_accept() завершается.
    // Она выполняет обработку запроса клиента и запуск нового акцептора.
    void handle_accept(TcpConnection::pointer new_connection, const boost::system::error_code& error)
    {
        if (!error)
        {
            new_connection->start();
        }

        start_accept();
    }

private:
    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
};


int main()
{
    try
    {
	    // io_context предоставляет службы ввода-вывода, которые будет использовать сервер, такие как сокеты.
        boost::asio::io_context io_context;
        TcpServer server(io_context);

        // Запуск асинхронных операций.
        io_context.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}








// #include <cstdlib>
// #include <iostream>
// #include <memory>
// #include <utility>
// #include <boost/asio.hpp>
// #include <optional>
// #include <vector>
// #include <fstream>
// #include <string>
// #include <filesystem>
// #include <experimental/filesystem>

// using boost::asio::ip::tcp;

// const auto buffer_size = 4096;
// using namespace std::literals;
// namespace fs = std::experimental::filesystem;

// #if !defined(MAX_PATH)
// #   define MAX_PATH (256)
// #endif

// #if defined(_WIN32)
// const wchar_t separ = fs::path::preferred_separator;
// #else
// const wchar_t separ = *reinterpret_cast<const wchar_t*>(&fs::path::preferred_separator);
// #endif

// class session
//   : public std::enable_shared_from_this<session>
// {
// public:
//   session(tcp::socket socket)
//     : socket_(std::move(socket))
//   {
//   }

//   void start()
//   {
//     do_read();
//   }

// private:


//     std::optional<fs::path> recv_file_path()
//     {
//         auto request_data = std::string(data_);
//         if (!request_data.size()) return std::nullopt;

//         auto cur_path = fs::current_path().wstring();
//         //auto file_path = fs::weakly_canonical(request_data).wstring();
//         auto file_path = fs::canonical(request_data).wstring();


//         #if defined(_WIN32)
//         std::transform(cur_path.begin(), cur_path.end(), cur_path.begin(),
//             [](wchar_t c) { return std::towlower(c); }
//         );
//         std::transform(file_path.begin(), file_path.end(), file_path.begin(),
//             [](wchar_t c) { return std::towlower(c); }
//         );
//         #endif
// //        if (file_path.find(cur_path) == 0)
// //        {
// //            file_path = file_path.substr(cur_path.length());
// //        }

//         //return fs::weakly_canonical(cur_path + separ + file_path);
//         return fs::canonical(cur_path + separ + file_path);
//     }


//     bool process()
//     {
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
//     }


//     bool send_buffer(const std::vector<char>& buffer)
//     {
//         size_t transmit_bytes_count = 0;
//         const auto size = buffer.size();

//         while (transmit_bytes_count != size)
//         {
// //            auto result = send(client_sock_, &(buffer.data()[0]) + transmit_bytes_count, size - transmit_bytes_count, 0);
// //            if (-1 == result)
// //            {
// //                if (need_to_repeat()) continue;
// //                return false;
// //            }

//             //transmit_bytes_count += result;
//         }

//         return true;
//     }


//     bool send_file(fs::path const& file_path)
//     {
//         if (!(fs::exists(file_path) && fs::is_regular_file(file_path))) return false;
//         std::vector<char> buffer(buffer_size);
//         std::ifstream file_stream(file_path, std::ifstream::binary);

//         if (!file_stream) return false;

//         std::cout << "Sending file " << file_path << "..." << std::endl;
//         while (file_stream)
//         {
//             file_stream.read(&buffer[0], buffer.size());
//             if (!send_buffer(buffer)) return false;
//         }
//         return true;
//     }


    


//   void do_read()
//   {
//     auto self(shared_from_this());
//     socket_.async_read_some(boost::asio::buffer(data_, max_length),
//         [this, self](boost::system::error_code ec, std::size_t length)
//         {
//           if (!ec)
//           {
//             std::cout << data_ << " " << length << std::endl;
//             do_write(length);
//           }
//         });
//   }

//   void do_write(std::size_t length)
//   {
//     auto self(shared_from_this());
//     boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
//         [this, self](boost::system::error_code ec, std::size_t /*length*/)
//         {
//           if (!ec)
//           {
//             do_read();
//           }
//         });
//   }

//   tcp::socket socket_;
//   enum { max_length = 1024 };
//   char data_[max_length];
// };




// class server
// {
// public:
//   server(boost::asio::io_context& io_context, short port)
//     : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
//   {
//     do_accept();
//   }

// private:
//   void do_accept()
//   {
//     acceptor_.async_accept(
//         [this](boost::system::error_code ec, tcp::socket socket)
//         {
//           if (!ec)
//           {
//             std::make_shared<session>(std::move(socket))->start();
//           }

//           do_accept();
//         });
//   }

//   tcp::acceptor acceptor_;
// };

// int main(int argc, char* argv[])
// {
//   try
//   {
//     if (argc != 2)
//     {
//       std::cerr << "Usage: async_tcp_echo_server <port>\n";
//       return 1;
//     }

//     boost::asio::io_context io_context;

//     server s(io_context, std::atoi(argv[1]));

//     io_context.run();
//   }
//   catch (std::exception& e)
//   {
//     std::cerr << "Exception: " << e.what() << "\n";
//   }

//   return 0;
// }