#include "file_io.h"
#include <iostream>
#include <cassert>

int main()
{
    std::string buffer;

    std::cout << "== FileIO tests ==\n";

    // 1. Create new file
    FileIO f("test.txt");
    assert(f.CreateNewFile());

    // 2. Save content
    assert(f.SaveFile("Hello World\nLine 2\n"));

    // 3. Load content
    assert(f.LoadFile(buffer));
    assert(buffer == "Hello World\nLine 2\n");

    // 4. Overwrite test
    assert(f.SaveFile("New content"));
    assert(f.LoadFile(buffer));
    assert(buffer == "New content");

    // 5. Rename test
    assert(f.RenameFile("renamed.txt") == 0);
    FileIO f2("renamed.txt");
    assert(f2.exists());

    // 6. Non-existent file
    FileIO bad("does_not_exist.txt");
    assert(!bad.LoadFile(buffer));

    std::cout << "All FileIO tests PASSED\n";
    return 0;
}

