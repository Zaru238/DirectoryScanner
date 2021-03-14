#pragma once

#include <boost/asio.hpp>
#include <memory>
#include <string>

class Session : public std::enable_shared_from_this<Session> {
 public:
  Session(boost::asio::local::stream_protocol::socket socket,
          std::string message);

  void AddToQueue();

 private:
  boost::asio::local::stream_protocol::socket socket_;
  const std::string message_;
};
