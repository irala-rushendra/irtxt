#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

int cnt_ = 0;
int main(int argc, char** argv){
  
  if(argc <= 1) {
    make_new_file("untitled",++cnt_);
  }else{
    make_new_file(argv[0]);
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
