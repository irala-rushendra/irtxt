#pragma once
#include <cstring>

namespace text_buffer_ {
  class TextBuffer {
    public:
      TextBuffer();
      ~TextBuffer();
      int loadBuffer(char *data, long length);
      int move_fwd(long distance);
      int move_bwd(long distance);
      int insert(char *data, long length);
      int remove(long length);
      void printBuffer();
    private:
      char *data;
      long capacity;
      long before_cursor_index;
      long after_cursor_index;
  };
}
