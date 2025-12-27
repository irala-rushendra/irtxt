#include "editor.h"
#include <string>
#include <cctype>

// These are function wrappers for the editor
void Core::EditorCore::insertText(const std::string& str){
  buffer.insert(str.c_str(),str.size());
}

Core::EditorCore::EditorCore() {
  buffer.loadBuffer("",0);
}

void Core::EditorCore::deleteBackward(){
  if(buffer.cursorPos() > 0){
    buffer.remove(1);
  }
}

void Core::EditorCore::moveToStart(){
  
  std::size_t pos = buffer.cursorPos();
  if(pos > 0) {
    buffer.mov_bwd(pos);
  }
}

void Core::EditorCore::moveToEnd(){
  std::size_t right = buffer.rightTextLength();

  if(right > 0){
    buffer.mov_fwd(right);
  }
}

void Core::EditorCore::moveWordLeft(){
  std::size_t pos = buffer.cursorPos();
  std::size_t dist = 0;

  while(pos > 0){
    char c = buffer.charAt(pos - 1);
    if(c != ' ' && c != '\t' && c != '\n')
      break;
    pos--;
    dist++;
  }

  while(pos > 0){
    char c = buffer.charAt(pos - 1);
    if(!std::isalnum(c) && c != '_')
      break;
    pos--;
    dist++;
  }

  if(dist > 0){
    buffer.mov_bwd(dist);
  }
}

void Core::EditorCore::moveWordRight(){
  std::size_t pos = buffer.cursorPos();
  std::size_t dist = 0;

  while(pos < buffer.textLength()){
    char c = buffer.charAt(pos);
    if(c != ' ' && c != '\t' && c != '\n')
      break;
    pos++;
    dist++;
  }

  while(pos < buffer.textLength()){
    char c = buffer.charAt(pos - 1);
    if(!std::isalnum(c) && c != '_')
      break;
    pos--;
    dist++;
  }

  if(dist > 0){
    buffer.mov_fwd(dist);
  }
}

void Core::EditorCore::moveLineStart(){
  
  std::size_t pos = buffer.cursorPos();
  std::size_t dist = 0;

  while(pos > 0){
    if(buffer.charAt(pos - 1) == '\n') 
      break;
    pos--;
    dist++;
  }

  if(dist > 0){
    buffer.mov_bwd(dist);
  }
}

void Core::EditorCore::moveLineEnd(){
  
  std::size_t pos = buffer.cursorPos();
  std::size_t dist = 0;

  while(pos < buffer.textLength()){
    if(buffer.charAt(pos) == '\n')
      break;
    pos++;
    dist++;
  }
  if(dist > 0){
    buffer.mov_fwd(dist);
  }
}

std::string Core::EditorCore::getLine() const {
  std::size_t start = buffer.cursorPos();

  while(start > 0){
    if(buffer.charAt(start - 1) == '\n')
      break;

    start--;
  }
  std::size_t end = buffer.cursorPos();
  while(end < buffer.textLength()){
    if(buffer.charAt(end) == '\n')
      break;

    end++;
  }
  std::string text = buffer.dump();
  return text.substr(start,end - start);
}

void Core::EditorCore::insertChar(char c){
  buffer.insert(&c,1);
}

void Core::EditorCore::insertNewLine(){
  buffer.insert("\n",1);
}

void Core::EditorCore::deleteForward(){
  
  if(buffer.rightTextLength() > 0) {
    buffer.removeForward(1);
  }
}

