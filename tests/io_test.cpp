
#include "file_io.h"
#include "editor.h"
#include <iostream>
#include <fstream>

static void writeTempFile(const std::string& path, const std::string& data) {
    std::ofstream f(path, std::ios::trunc);
    f << data;
}

int main() {
    const std::string inputPath  = "test_input.txt";
    const std::string outputPath = "test_output.txt";

    // Prepare input file
    writeTempFile(inputPath, "Hello file IO\nSecond line");

    Core::EditorCore ed;

    std::cout << "=== LOAD FILE ===\n";
    if (!ed.openFile(inputPath)) {
        std::cout << "Failed to open file\n";
        return 1;
    }

    std::cout << "Current line: [" << ed.getLine() << "]\n";

    std::cout << "\n=== MODIFY ===\n";
    ed.moveToEnd();
    ed.insertNewLine();
    ed.insertText("Appended line");
    std::cout << "After modify: [" << ed.getLine() << "]\n";

    std::cout << "\n=== SAVE FILE ===\n";
    if (!ed.saveFile(outputPath)) {
        std::cout << "Failed to save file\n";
        return 1;
    }

    std::cout << "Saved to " << outputPath << "\n";

    std::cout << "\n=== VERIFY OUTPUT ===\n";
    std::ifstream out(outputPath);
    std::cout << out.rdbuf();

    std::cout << "\n\nDONE\n";
    return 0;
}
