#include "directory_scanner.h"

#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

const std::string kExtension = ".wav";

void DirectoryScanner::Update() {
  std::stringstream new_content;

  for (const auto& entry : fs::directory_iterator(fs::current_path())) {
    if (entry.path().extension() == kExtension) {
      new_content << entry.path().parent_path() << " "
                  << entry.path().filename() << " " << entry.file_size()
                  << std::endl;
    }
  }

  content_ = new_content.str();
}

const std::string& DirectoryScanner::Get() const { return content_; }
