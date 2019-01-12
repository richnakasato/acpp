#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter an edge size: ";
    unsigned int size;
    std::cin >> size;
    std::cout << std::endl;

    // triangle
    for (int i=0; i<size; ++i) {
        const std::string line(i+1, '*');
        std::cout << line << std::endl;
    }
    std::cout << std::endl;

    // "square"
    for (int i=0; i<size; ++i) {
        const std::string line(size, '*');
        std::cout << line << std::endl;
    }
    std::cout << std::endl;

    // "rectangle"
    for (int i=0; i<size; ++i) {
        const std::string line(size*2, '*');
        std::cout << line << std::endl;
    }

    return 0;
}
