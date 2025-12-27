#include "file_io.h"
#include <fstream>
#include <sstream>

bool IO::loadFromFile(const std::string& path, std::string& out){
  std::ifstream file(path, std::ios::in | std::ios::binary);
  if(!file)
    return false;

  std::ostringstream ss;
  ss << file.rdbuf();
  out = ss.str();
  return true;

}

bool IO::saveToFile(const std::string& path, const std::string& data){
  std::ofstream file(path, std::ios::out | std::ios::binary | std::ios::trunc);
  if(!file)
    return false;
  file << data;
  return true;
}
