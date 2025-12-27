#pragma once
#include "text_buffer.h"
#include <string>
namespace Core {
  class EditorCore {
    private:
      TextBuffer::GapBufferImpl buffer;
    public:
      EditorCore();
      void insertText(const std::string& str);
      void deleteBackward();
      void moveToStart();
      void moveToEnd();
      void moveWordLeft();
      void moveWordRight();
      void moveLineStart();
      void moveLineEnd();
      std::string getLine() const;
      void insertChar(char c);
      void insertNewLine();
      void deleteForward();
      bool openFile(const std::string& path);
      bool saveFile(const std::string& path) const;
  };
  
}


