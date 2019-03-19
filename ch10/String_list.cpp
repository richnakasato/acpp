#include <iostream>
#include <vector>

#include "split.h"
#include "String_list.h"

void rvn::String_list::push_back(const std::string& s)
{
    strs.push_back(s);
}

void rvn::String_list::push_front(const std::string& s)
{
    strs.push_front(s);
}

int main()
{
    rvn::String_list test = rvn::String_list(10, "bob");
    test.push_back("test");
    for (const auto& t : test) {
        std::cout << t << " ";
    }
    std::cout << std::endl;

    for (rvn::String_list::iterator it=test.begin();
         it!=test.end(); ++it) {
        *it = "replaced";
    }
    for (const auto& t : test) {
        std::cout << t << " ";
    }
    std::cout << std::endl;


    std::string str = "the cat in the hat is the best cat";
    rvn::String_list result = split<rvn::String_list>(str);
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }

    std::cout << "--" << std::endl;

    std::vector<std::string> vresult = split<std::vector<std::string>>(str);
    for (const auto& s : vresult) {
        std::cout << s << std::endl;
    }

    //rvn::String_list test = rvn::String_list();
    return 0;
}
