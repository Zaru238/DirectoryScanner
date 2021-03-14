#include "server.h"

#include <boost/log/trivial.hpp>
#include <chrono>
#include <iostream>
#include <memory>

#include "session.h"

using local_protocol = boost::asio::local::stream_protocol;

Server::Server(const std::string& path)
    : acceptor_(io_context_, local_protocol::endpoint(path)),
      timer_content_(io_context_) {
  DoAccept();
  DoUpdateContent();
}

void Server::Server::Run() { io_context_.run(); }

void Server::DoAccept() {
  acceptor_.async_accept([this](boost::system::error_code error_code,
                                local_protocol::socket socket) {
    if (!error_code) {
      BOOST_LOG_TRIVIAL(info) << "Get new connection";
      std::string content = scanner_.Get();
      auto session =
          std::make_shared<Session>(std::move(socket), std::move(content));
      session->AddToQueue();
    } else {
      BOOST_LOG_TRIVIAL(error) << "Get error during connection " << error_code;
    }

    DoAccept();
  });
}

void Server::DoUpdateContent() {
  timer_content_.expires_after(std::chrono::seconds(1));
  timer_content_.async_wait([this](boost::system::error_code error_code) {
    scanner_.Update();
    DoUpdateContent();
  });
}

