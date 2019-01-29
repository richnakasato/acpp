#include <algorithm>
#include <cassert>
#include <string>

bool is_palindrome(const std::string& str)
{
    return std::equal(str.begin(), str.end(), str.rbegin());
}

int main()
{
    std::string str1 = "racecar";
    std::string str2 = "dontknow";
    assert(is_palindrome(str1));
    assert(!is_palindrome(str2));

    return 0;
}
