#include <common/common.h>

#include <boost/asio.hpp>
#include <iostream>

using local_protocol = boost::asio::local::stream_protocol;

int main() {
  try {
    boost::asio::io_context io_context;

    local_protocol::socket s(io_context);
    s.connect(local_protocol::endpoint(common::kSocketPath));

    boost::system::error_code ec;
    boost::asio::streambuf buffer;
    boost::asio::read(s, buffer, ec);

    std::cout << "Find the following files:" << std::endl << &buffer;
  } catch (const std::exception& exception) {
    std::cout << "Get exception " << exception.what() << std::endl;
  } catch (...) {
    std::cout << "Get nonstandard exception" << std::endl;
  }

  return 0;
}
