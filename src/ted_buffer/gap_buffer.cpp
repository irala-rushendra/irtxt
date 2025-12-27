#include <cstring>
#include "text_buffer.h"
#include <string>
#include <cstdio>
#include <unistd.h>
#include <cstddef>
/*Author : Irala Rushendra | email = rushendrairala@gmail.com*/
/*
 * This Section explains implementation of gap_buffer using the text_buffer interface defined in the text_editor_ namespace in include directory
 *
 * What is a Gap Buffer?
 * -> Unlike using a plain old string to get input which will be hard and computationally inefficient when required to modify.
 * -> Gap buffer utilizes and implements as a small empty gap is preoccupied in the after cursor region. When required to edit each letter will be shifted to empty buffer region.
 *  
 */

TextBuffer::GapBufferImpl::GapBufferImpl() : data(nullptr), capacity(0), startOffset(0), endOffset(0) {}
TextBuffer::GapBufferImpl::~GapBufferImpl() {
  delete[] data;
}
// eg: this is some text
// [this is some text][      Gap      ]
bool TextBuffer::GapBufferImpl::loadBuffer(const char *data, std::size_t length) {
  // If invalid data is parsed return false (validation step)
  if(!data) return false;
  if(length > 4096) return false;
  delete[] this->data;
  // Dynamically allocate memory buffer capacity of 4096 bytes (Giant chunk of memory)
  this->data = new char[4096];
  capacity = 4096;

  std::memset(this->data,0,capacity);
  //[this][    Gap    ] here starting offset would be 5 as (this - 4 + /0 - 1 = 5)
  std::memcpy(this->data,data,length);
  startOffset = length;
  endOffset = capacity;
  return true;
}
// lets say editing has to done at 'some' and cursor is at 'is'
// 1.[this is some text][   Gap   ]
// 2.[this is some [   gap   ] text]
// 3.[this is [   gap   ] some text]
// mov_fwd corresponds to 3 -> 2 transition whereas mov_bwd corresponds to 1 --> 2 transition
bool TextBuffer::GapBufferImpl::mov_fwd(std::size_t distance){
  while(distance--){
    if(endOffset == capacity) return false;
    data[startOffset] = data[endOffset];
    endOffset++;
    startOffset++;
  }
  return true;
}
bool TextBuffer::GapBufferImpl::mov_bwd(std::size_t distance){
  while(distance--){
    if(startOffset == 0) return false;
    endOffset--;
    startOffset--;
    data[endOffset] = data[startOffset];
  }
  return true;
}
/*
 * The above code decreases distance by one and shifts by assigning values of the traversing side to the other side
 * This way the entire buffer can be moved
 */
bool TextBuffer::GapBufferImpl::insert(const char *data, std::size_t length){
  // validation step
  if(!data) return false;

  // if the size of buffer is less than length it cannot accomodate the text for insertion.
  if(endOffset - startOffset < length) return false;

  while(length--){
    this->data[startOffset++] = *data++;
  }
  return true;
}

bool TextBuffer::GapBufferImpl::remove(std::size_t length){
  // if the length of deletion is greater than the starting offset that means its at the end and cannot delete anything.
  if (length > startOffset) return false;
  startOffset -= length;
  return true;
}

bool TextBuffer::GapBufferImpl::removeForward(std::size_t length) {
  if(length > (capacity - endOffset)) return false;
  endOffset += length;
  return true;
}

void TextBuffer::GapBufferImpl::print(){
  for(std::size_t i = 0;i<startOffset;++i){
    putchar(data[i]);
  }
  for(std::size_t i = endOffset;i<capacity;++i){
    putchar(data[i]);
  }
  putchar('\n');
}

std::string TextBuffer::GapBufferImpl::dump() const {
  std::string final_string = "";
  for(std::size_t i = 0;i < startOffset;++i){
    final_string += data[i];
  }
  for(std::size_t i = endOffset; i < capacity ; ++i){
    final_string += data[i];
  }
  return final_string;
}

std::string TextBuffer::GapBufferImpl::dumpImproved() const {
  std::string out;
  out.reserve(startOffset + (capacity - endOffset));
  out.append(data, startOffset);
  out.append(data + endOffset, capacity - endOffset);

  return out;
  
}

std::size_t TextBuffer::GapBufferImpl::cursorPos() const {
  return startOffset;
}

std::size_t TextBuffer::GapBufferImpl::textLength() const {
  return (startOffset + (capacity - endOffset));
}

std::size_t TextBuffer::GapBufferImpl::rightTextLength() const {
  return (capacity - endOffset);
}

char TextBuffer::GapBufferImpl::charAt(std::size_t pos) const {
  std::size_t logicalLength = startOffset + (capacity - endOffset);
  
  if(pos >= logicalLength) return '\0';

  if(pos < startOffset){
    return data[pos];
  }else{
    return data[pos + (endOffset - startOffset)];
  }

}
