#include <cstring>
#include "text_buffer.h"
#include <cstdio>
#include <unistd.h>
#include <cstddef.h>
/*Author : Irala Rushendra | email = rushendrairala@gmail.com*/
/*
 * This Section explains implementation of gap_buffer using the text_buffer interface defined in the text_editor_ namespace in include directory
 *
 * What is a Gap Buffer?
 * -> Unlike using a plain old string to get input which will be hard and computationally inefficient when required to modify.
 * -> Gap buffer utilizes and implements as a small empty gap is preoccupied in the after cursor region. When required to edit each letter will be shifted to empty buffer region.
 *  
 */

text_buffer::TextBuffer::GapBufferImpl() {
  memset(this, 0 , sizeof(GapBufferImpl));
}
text_buffer::TextBuffer::~GapBufferImpl() {
  if (data != nullptr){
    delete[] data;
    memset(this , 0, sizeof(GapBufferImpl));
  }
}
// eg: this is some text
// [this is some text][      Gap      ]
bool TextBuffer::GapBufferImpl::loadBuffer(const char *data, std::size_t length) {
  // If invalid data is parsed return false (validation step)
  if(!data) return false;
  if(length > 4096) return false;
  // Dynamically allocate memory buffer capacity of 4096 bytes (Giant chunk of memory)
  this->data = new char[4096];
  capacity = 4096;
  //[this][    Gap    ] here starting offset would be 5 as (this - 4 + /0 - 1 = 5)
  std::memcpy(this->data,data,length);
  startOffset = length;
  endOffset = capacity;
  return true;
}
// lets say editing has to done at 'some' and cursor is at 'is'
// 
bool TextBuffer::GapBufferImpl::mov_fwd(std::size_t distance){
  ;
}
bool TextBuffer::GapBufferImpl::mov_bwd(std::size_t distance){
  ;
}

bool TextBuffer::GapBufferImpl::insert(const char *data, std::size_t length){
  ;
}

bool TextBuffer::GapBufferImpl::remove(std::size_t length){
  ;
}

void TextBuffer::GapBufferImpl::print(){
  ;
}
