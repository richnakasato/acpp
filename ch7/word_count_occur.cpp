#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::map<std::string,int> counts;
    while (std::cin >> s) {
        ++counts[s];
    }
    std::multimap<int,std::string> occurs;
    for (std::map<std::string,int>::const_iterator it = counts.begin();
         it != counts.end();
         ++it) {
        occurs.insert({it->second, it->first});
        //std::cout << it->first << ": " << it->second << std::endl;
    }
    for (std::multimap<int,std::string>::const_iterator it=occurs.begin();
         it != occurs.end();
         ++it) {
        std::cout << it->second << ": " << it->first << std::endl;
    }
    return 0;
}
