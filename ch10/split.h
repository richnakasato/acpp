#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm>
#include <string>

bool space(char);
bool not_space(char);

template <typename T>
T split(const std::string& s)
{
    T result;
    std::string::const_iterator i = s.begin();
    while (i != s.end()) {
        i = std::find_if(i, s.end(), not_space);
        std::string::const_iterator j = std::find_if(i, s.end(), space);
        if (i != s.end()) {
            result.push_back(std::string(i,j));
        }
        i = j;
    }
    return result;
}


#endif // GUARD_split_h
