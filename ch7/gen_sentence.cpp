#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "split.h"

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream& in)
{
    Grammar ret;
    std::string line;
    while (getline(in, line)) {
        std::vector<std::string> entry = split(line);
        if (!entry.empty()) {
            ret[entry[0]].push_back(
                    Rule(entry.begin()+1, entry.end()));
        }
    }
    return ret;
}

std::vector<std::string> gen_sentence(const Grammar& g)
{
    std::vector<std::string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

bool bracketed(const std::string& s)
{
    return !s.empty() && s[0] == '<' && s[s.size()-1] == '>';
}

int main()
{
    return 0;
}
