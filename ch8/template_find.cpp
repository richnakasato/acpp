#include <iostream>
#include <string>
#include <vector>

template <class X, class Y> X find(X begin, X end, const Y& target)
{
    X iter = begin;
    while (iter != end && (*iter) != target) {
        ++iter;
    }
    return iter;
}

int main()
{
    std::string test1 {"abcdefghijk"};
    std::vector<int> test2 {1,2,3,4,5,6,7};
    std::string::iterator test1_it = find(test1.begin(), test1.end(), 'c');
    std::vector<int>::iterator test2_it = find(test2.begin(), test2.end(), 4);
    if (test1_it != test1.end()) std::cout << *test1_it << std::endl;
    if (test2_it != test2.end()) std::cout << *test2_it << std::endl;
    return 0;
}
