#include <iostream>
#include <string>

#include "split.h"

int main()
{
    std::string s;
    while (getline(std::cin, s)) {
        std::vector<std::string> v = split(s);
        for (std::vector<std::string>::size_type i=0; i!=v.size(); ++i) {
            std::cout << v[i] << std::endl;
        }
    }
    return 0;
}
