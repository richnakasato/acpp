#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello, world!" << std::endl;
    3 + 4;
    std::cout << "This (\") is a quote, and this (\\) is a backslash." << std::endl;
    std::cout << "\tThis line starts with a tab." << std::endl;
    std::ifstream f("hello_world.txt");
    if (f.is_open()) {
        std::cout << f.rdbuf();
    }
    std::cout << "This is the last line." << std::endl;
    return 0;
}
