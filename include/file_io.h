#pragma once
#include <string>
<<<<<<< HEAD


namespace IO {
  bool loadFromFile(const std::string& path, std::string& out);
  bool saveToFile(const std::string& path, const std::string& data);
  
}
=======
#include <fstream>


class FileIO
{
  public:
  explicit FileIO(std::string fname = "untitled");

  bool exists() const;
  bool readable() const;
  bool writeable() const;
  bool CreateNewFile();
  bool LoadFile(std::string& outBuffer);
  bool SaveFile(const std::string& buffer);
  int RenameFile(const std::string& newName);

  const std::string& getName() const;
  private:
    std::string fname;
};
>>>>>>> ff472fa (Added FILE IO functions)
