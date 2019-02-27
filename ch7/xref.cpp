#include <iostream>
#include <map>
#include <set>
#include <string>

#include "split.h"

std::map<std::string, std::vector<int>> xref(std::istream& in,
                                             std::vector<std::string> find_words(const std::string&) = split)
{
    std::string line;
    int line_num = 0;
    std::map<std::string, std::vector<int>> result;
    while (getline(in, line)) {
        ++line_num;
        std::vector<std::string> words = find_words(line);
        std::set<std::string> seen;
        for (std::vector<std::string>::const_iterator it=words.begin();
             it!=words.end(); ++it) {
            if (seen.find(*it) == seen.end()) {
                result[*it].push_back(line_num);
                seen.insert(*it);
            }
        }
    }
    return result;
}

int main()
{
    std::map<std::string, std::vector<int>> result = xref(std::cin);
    for (std::map<std::string,std::vector<int>>::const_iterator it=result.begin();
         it!=result.end(); ++it) {
        std::cout << it->first << " occurs on line(s): ";
        for (std::vector<int>::const_iterator jt=it->second.begin();
             jt!=it->second.end(); ++jt) {
            std::cout << *jt << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
