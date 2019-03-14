#include <iostream>
#include <list>

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

    //rvn::String_list test = rvn::String_list();
    return 0;
}
