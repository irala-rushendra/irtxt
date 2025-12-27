#pragma once
#include <string>


namespace IO {
  bool loadFromFile(const std::string& path, std::string& out);
  bool saveToFile(const std::string& path, const std::string& data);
  
}
