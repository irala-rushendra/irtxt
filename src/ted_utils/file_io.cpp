<<<<<<< HEAD
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
=======
#include <string>
#include "file_io.h"
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>

FileIO::FileIO(std::string fname) : fname(std::move(fname)) {}


bool FileIO::exists() const
{
  std::ifstream file(fname);
  return file.good();
}

bool FileIO::CreateNewFile()
{
  std::ofstream file(fname);
  return file.good();
}

bool FileIO::readable() const{

  std::ifstream file(fname);
  if(!file.good())
  {
    std::cerr << "[ERROR] The File is not readable : " + fname << std::endl;
    return false;
  }
  return true;
}

bool FileIO::writeable() const
{
  std::ofstream file(fname, std::ios::app);
  if(!file.good())
  {
    std::cerr << "[ERROR] The File is not writeable : " + fname << std::endl;
    return false;
  }
  return true;
}
bool FileIO::SaveFile(const std::string& buffer) 
{
  if(!writeable()) return false;
  std::ofstream outfile(fname, std::ios::trunc);
  outfile << buffer;

  return outfile.good();
}
bool FileIO::LoadFile(std::string& outBuffer)
{
  if(readable())
  {
    std::ifstream infile(fname);
    std::ostringstream ss;
    ss << infile.rdbuf();
    outBuffer = ss.str();
  }else{
    std::cerr << "The provided file does not exists or cannot be read!!!" << std::endl;
    return false;
  }

  return true;
}

int FileIO::RenameFile(const std::string& newName)
{
  int result = std::rename(fname.c_str(),newName.c_str());
  if (result == 0) fname = newName;
  return result;
}

const std::string& FileIO::getName() const 
{
  return fname;
}
>>>>>>> ff472fa (Added FILE IO functions)
