#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    int fail_count = 0;
    for (int i=1; i<argc; ++i) {
        std::ifstream in(argv[i]);
        if (in) {
            std::string s;
            while (std::getline(in, s)) {
                std::cout << s << std::endl;
            }
        }
        else {
            std::cout << "error reading file " << argv[i] << std::endl;
            ++fail_count;
        }
    }
    return fail_count;
}

