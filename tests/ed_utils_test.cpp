#include "editor.h"
#include <iostream>

static void dump(const char* label, Core::EditorCore& ed) {
    std::cout << label << " => [" << ed.getLine() << "]\n";
}

int main() {
    Core::EditorCore ed;

    std::cout << "=== BASIC INSERT ===\n";
    ed.insertText("Hello world");
    dump("After insert", ed);

    std::cout << "\n=== NEW LINE ===\n";
    ed.insertNewLine();
    ed.insertText("Second line");
    dump("Line 2", ed);

    std::cout << "\n=== MOVE WORD LEFT + INSERT ===\n";
    ed.moveWordLeft();
    dump("After moveWordLeft", ed);

    ed.insertText(" awesome");
    dump("After inserting ' awesome'", ed);

    std::cout << "\n=== MOVE LINE START ===\n";
    ed.moveLineStart();
    dump("After moveLineStart", ed);

    std::cout << "\n=== MOVE LINE END ===\n";
    ed.moveLineEnd();
    dump("After moveLineEnd", ed);

    std::cout << "\n=== DELETE BACKWARD ===\n";
    ed.deleteBackward();
    dump("After deleteBackward", ed);

    std::cout << "\n=== FINAL DUMP ===\n";
    std::cout << ed.getLine() << "\n";

    return 0;
}

