#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string s;
    std::map<std::string,int> counts;
    while (std::cin >> s) {
        ++counts[s];
    }
    for (std::map<std::string,int>::const_iterator it = counts.begin();
         it != counts.end();
         ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    return 0;
}
