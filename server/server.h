#pragma once

#include <boost/asio.hpp>
#include <string>

#include "directory_scanner.h"

class Server {
 public:
  Server(const std::string& path);
  void Run();

 private:
  void DoAccept();
  void DoUpdateContent();

  boost::asio::io_context io_context_;
  boost::asio::local::stream_protocol::acceptor acceptor_;
  boost::asio::steady_timer timer_content_;
  DirectoryScanner scanner_;
};
