#pragma once

#include <boost/asio.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/write.hpp>
#include <memory>
#include <string>

class EchoServer {
private:
  class Connection {
  public:
    boost::asio::ip::tcp::socket socket;
    Connection(boost::asio::io_context &io_context);
  };

  boost::asio::io_context io_context;
  boost::asio::ip::tcp::endpoint endpoint;
  boost::asio::ip::tcp::acceptor acceptor;

  void handle_request(std::shared_ptr<Connection> connection);
  void accept();

public:
  EchoServer();
  void start();
};
