#pragma once
#include <cstring>
#include <cstddef>
#include <string>

//This is supposed to be moduluar like user can change text buffers as they wish. Only Gap Buffer is implemented as of now
namespace TextBuffer {
  class GapBufferImpl {
    private:
      char *data;
      std::size_t capacity;
      std::size_t startOffset;
      std::size_t endOffset;

    public:
      GapBufferImpl();
      ~GapBufferImpl();
      bool loadBuffer(const char *data, std::size_t length);
      bool insert(const char *data, std::size_t length);
      bool remove(std::size_t length);
      bool removeForward(std::size_t length);
      void print();
      bool mov_fwd(std::size_t distance);
      bool mov_bwd(std::size_t distance);
      std::string dump() const;
      std::string dumpImproved() const;
      std::size_t cursorPos() const;
      std::size_t textLength() const;
      std::size_t rightTextLength() const;
      char charAt(std::size_t pos) const;
  };
}
