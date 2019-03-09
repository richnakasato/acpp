#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if (argc == 0) return 0;
    for (int i=1; i!=argc; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

