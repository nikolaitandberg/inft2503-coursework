#include "EchoServer.hpp"
#include <boost/asio.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/write.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

EchoServer::Connection::Connection(class io_context &io_context)
    : socket(io_context) {}

EchoServer::EchoServer()
    : endpoint(tcp::v4(), 8080),
      acceptor(io_context, endpoint) {}

void EchoServer::start() {
  accept();
  io_context.run();
}

void EchoServer::accept() {
  auto connection = make_shared<Connection>(io_context);

  acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
    accept(); // Start accepting next connection

    if (!ec) {
      handle_request(connection);
    }
  });
}

void EchoServer::handle_request(shared_ptr<Connection> connection) {
  auto read_buffer = make_shared<boost::asio::streambuf>();

  async_read_until(connection->socket, *read_buffer, "\r\n",
                   [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                     if (!ec) {
                       istream read_stream(read_buffer.get());
                       string message;
                       getline(read_stream, message);
                       if (!message.empty() && message.back() == '\r')
                         message.pop_back();

                       cout << "Message from a connected client: " << message << endl;

                       if (message == "exit") {
                         connection->socket.close();
                         return;
                       }

                       auto write_buffer = make_shared<boost::asio::streambuf>();
                       ostream write_stream(write_buffer.get());
                       if (message.size() >= 5 && message.substr(0, 5) == "GET /") {

                         size_t path_start = 4; // rett etter "GET"
                         size_t path_end = message.find(' ', path_start);
                         std::string path = message.substr(path_start, path_end - path_start);

                         std::string response_body;
                         std::string status_line;
                         std::string content_type = "text/plain";

                         if (path == "/") {
                           response_body = "Dette er hjemmesiden";
                           status_line = "HTTP/1.1 200 OK";
                         } else if (path == "/en_side") {
                           response_body = "Dette er en annen side";
                           status_line = "HTTP/1.1 200 OK";
                         } else {
                           response_body = "404 Not Found";
                           status_line = "HTTP/1.1 404 Not Found";
                         }

                         std::ostringstream response_stream;
                         response_stream << status_line << "\r\n"
                                         << "Content-Type: " << content_type << "\r\n"
                                         << "Content-Length: " << response_body.size() << "\r\n"
                                         << "Connection: close\r\n"
                                         << "\r\n"
                                         << response_body;

                         write_stream << response_stream.str();
                       } else {
                         // Echo back the message
                         write_stream << message << endl;
                       }

                       async_write(connection->socket, *write_buffer,
                                   [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                     if (!ec)
                                       handle_request(connection);
                                   });
                     }
                   });
}
