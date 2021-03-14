#include "session.h"

#include <boost/log/trivial.hpp>

Session::Session(boost::asio::local::stream_protocol::socket socket,
                 std::string message)
    : socket_(std::move(socket)), message_(std::move(message)){};

void Session::AddToQueue() {
  auto self(shared_from_this());
  boost::asio::async_write(
      socket_, boost::asio::buffer(message_.c_str(), message_.length()),
      [self](boost::system::error_code error_code, std::size_t) {
        if (!error_code) {
          BOOST_LOG_TRIVIAL(info) << "Content has been successfully sent";
        } else {
          BOOST_LOG_TRIVIAL(error) << "Get error during sending " << error_code;
        }
      });
}

