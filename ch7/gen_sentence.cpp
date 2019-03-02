#include <cstdlib>
#include <exception>
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

bool bracketed(const std::string& s)
{
    return !s.empty() && s[0] == '<' && s[s.size()-1] == '>';
}

int nrand(int n)
{
    if (0 < n && n <= RAND_MAX) {
        const int bucket_size = RAND_MAX / n;
        int r;
        do {
            r = rand() / bucket_size;
        } while (r >= n);
        return r;
    }
    return 0;
}

void gen_aux(const Grammar& g, const std::string& word, std::vector<std::string>& ret)
{
    if (!bracketed(word)) {
        ret.push_back(word);
    }
    else {
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw std::logic_error("empty rule");
        const Rule_collection& c = it->second;
        const Rule& r = c[nrand(c.size())];
        for (Rule::const_iterator i=r.begin(); i!=r.end(); ++i) {
            gen_aux(g, *i, ret);
        }
    }
}

std::vector<std::string> gen_sentence(const Grammar& g)
{
    std::vector<std::string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

int main()
{
    std::vector<std::string> sentence = gen_sentence(read_grammar(std::cin));
    for (std::vector<std::string>::const_iterator it=sentence.begin();
         it!=sentence.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}

