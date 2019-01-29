#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

std::vector<std::string> split(const std::string& str)
{
    std::vector<std::string> result;
    std::string::const_iterator i = str.begin();
    while (i != str.end()) {
        i = std::find_if(i, str.end(), not_space);
        std::string::const_iterator j = std::find_if(i, str.end(), space);
        if (i != str.end()) {
            result.push_back(std::string(i,j));
        }
        i = j;
    }
    return result;
}

int main()
{
    std::string str = "the cat in the hat is the best cat";
    std::vector<std::string> result = split(str);
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }
    return 0;
}
