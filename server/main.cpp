#include <common/common.h>

#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <iostream>

#include "server.h"

const std::string kLogFilename = "error.log";

int main() {
  try {
    boost::log::add_file_log(
        boost::log::keywords::file_name = kLogFilename,
        boost::log::keywords::auto_flush = true,
        boost::log::keywords::open_mode = std::ios_base::app);
    BOOST_LOG_TRIVIAL(info) << "Server start";

    std::remove(common::kSocketPath.c_str());

    Server server(common::kSocketPath);
    server.Run();

  } catch (const std::exception& exception) {
    BOOST_LOG_TRIVIAL(error) << "Get exception " << exception.what();
  } catch (...) {
    BOOST_LOG_TRIVIAL(error) << "Get nonstandard exception";
  }

  return 0;
}
