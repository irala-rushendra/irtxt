#include <cstring>
#include "text_buffer.h"
#include <cstdio>
#include <unistd.h>
text_buffer::text_buffer_::TextBuffer() {
  memset(this,0,sizeof(TextBuffer));
}
text_buffer::text_buffer_::~TextBuffer() {
  if(data != nullptr) {
    delete[] data;
    memset(this, 0, sizeof(TextBuffer));
  }
}
int text_buffer::text_buffer_::loadBuffer(char *data, long length){
  /* I am allocating Memory with a buffer capacity of 4096 bytes*/
  this->data = new char[4096];
  capacity = 4096;
  before_cursor_index = length;
  after_cursor_index = 4096;
  memcpy(this->data, data, length);
  return 0;
}
int text_buffer::text_buffer_::mov_fwd(long distance){
  if (after_cursor_index + distance >= capacity) {
    return 0;
  }
  data[before_cursor_index] = data[after_cursor_index];
  return 1;
}
int text_buffer::text_buffer_::mov_bwd(long distance){
  if (before_cursor_index - distance < 0){
    return 0;
  }
  before_cursor_index--;
  after_cursor_index--;
  data[after_cursor_index] = data[before_cursor_index];
  return 1;
}
int text_buffer::text_buffer_::insert(char *data, long length){
  if (before_cursor_index == after_cursor_index){
    return 0;
  }
 this->data[before_cursor_index] = data[0];
 before_cursor_index++;
 return 1;
}

