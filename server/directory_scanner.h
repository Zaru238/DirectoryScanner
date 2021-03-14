#pragma once

#include <string>

class DirectoryScanner {
 public:
  void Update();
  const std::string& Get() const;

 private:
  std::string content_;
};
