#include <iostream>
#include <string>
#include <vector>

template<class ReadIt, class DataType>
ReadIt find(ReadIt begin, ReadIt end, const DataType& x)
{
    while (begin != end && *begin != x)
        ++begin;
    return begin;
}

template<class ReadIt, class WriteIt>
WriteIt my_copy(ReadIt begin, ReadIt end, WriteIt dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

template<class ForIt, class DataType>
void replace(ForIt beg, ForIt end, const DataType& x, const DataType& y)
{
    while (beg != end) {
        if (*beg == x)
            *beg = y; // can't do ++ here cause we'll only increment if == x
        ++beg;
    }
    return;
}

int main()
{
    std::vector<int> test {1,2,3,4,5,6,7};

    std::cout << "find" << std::endl;
    std::vector<int>::iterator it = find(test.begin(), test.end(), 4);
    std::cout << *it << std::endl;

    std::cout << "copy" << std::endl;
    std::vector<int> dest(test.size(), 0);
    for (const auto& num : dest) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    if (my_copy(test.begin(), test.end(), dest.begin()) == dest.end()) {
        for (const auto& num : dest) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << "replace" << std::endl;
    for (const auto& num : test)
        std::cout << num << ", ";
    std::cout << std::endl;
    replace(test.begin(), test.end(), 4, 7);
    for (const auto& num : test)
        std::cout << num << ", ";
    std::cout << std::endl;

    return 0;
}
