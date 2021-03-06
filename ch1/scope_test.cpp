#include <iostream>
#include <string>

int main()
{
    { const std::string s = "a string";         // separate scopes, okay
      std::cout << s << std::endl; }
    { const std::string s = "another string";
      std::cout << s << std::endl; }

    { const std::string s = "a string";         // this works because of hidden
      std::cout << s << std::endl;              // scope, think of variable
    { const std::string s = "another string";   // inside function with same
      std::cout << s << std::endl; };}          // name as calling function var

    { std::string s = "a string";
    { std::string x = s + ", really";
    std::cout << x << std::endl; }              // x out of scope with '}'
    std::cout << s << std::endl;                // can fix with swap x,s
    }                                           // or move '}'

    return 0;
}
