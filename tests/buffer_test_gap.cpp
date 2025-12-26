#include "text_buffer.h"



int main() {
    TextBuffer::GapBufferImpl buf;

    buf.loadBuffer("ABCDE", 5);
    buf.print();            // ABCDE|

    buf.mov_bwd(2);
    buf.print();            // ABC|DE  (text SAME)

    buf.insert("X", 1);
    buf.print();            // ABCX|DE

    buf.remove(1);
    buf.print();            // ABC|DE

    buf.mov_fwd(2);
    buf.insert("Y", 1);
    buf.print();            // ABCDEY|

    return 0;
}
