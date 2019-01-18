#include <cctype>
#include <iostream>

#include "split.h"

std::vector<std::string> split(const std::string& s)
{
    std::vector<std::string> ret;
    typedef std::string::size_type str_size;
    str_size i = 0;

    while (i != s.size()) {
        while (i != s.size() && std::isspace(s[i])) {
            ++i;
        }
        str_size j = i;
        while (j != s.size() && !std::isspace(s[j])) {
            ++j;
        }
        if (i != j) {
            str_size num_chars = j-i;
            ret.push_back(s.substr(i, num_chars));
            i = j;
        }
    }
    return ret;
}
