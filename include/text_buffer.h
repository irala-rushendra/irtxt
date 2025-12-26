#pragma once
#include <cstring>
#include <cstddef.h>
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
      void print() const;
      bool mov_fwd(std::size_t distance);
      bool mov_bwd(std::size_t distance);

  }
}
