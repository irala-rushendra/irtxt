#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <fstream>
#include "/ted_buffer/gap_buffer.cpp"

FILE* open_file(std::string fname, int cnt = 0){
  if(fname == "untitled"){
    std::string new_file_name = "untitled " + cnt;
    fstream fileout(new_file_name,ios::out);
    return fileout;
  }else{
    FILE* fileapp = fopen(fname, "r")
    return fileapp;
  }
}

int cnt_ = 0;
int main(int argc, char** argv){
  
  FILE* current_file;

  if(argc < 1) {
    current_file = open_file("untitled",++cnt_);
  }else{
    current_file = open_file(argv[1]);
  }
  


  std::unordered_map<std::string,std::function<void()>> _avail_tags_map;
  _avail_tags_map["-h"] = [] {
    std::cout << "[irtxt] : Help Section Invoked" << std::endl;
    std::cout << "1. For editing an instance --> irtxt [filename]" << std::endl;
    std::cout << "2. For making a untitled instance --> irtxt" <<std::endl;
  };
  _avail_tags_map["-v"] = [] {
    std::cout << "IRTXT - Irala Rushendra Text Editor /n Version : 1.0 (Beta)" << std::endl;
  };

  
}
