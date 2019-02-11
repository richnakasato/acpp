#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace rvn
{
    template<class RandIt, class X> bool binary_search(RandIt begin, RandIt end, const X& x)
    {
        while (begin != end) {
            RandIt mid = begin + (end - begin) / 2;
            if (*mid == x) return true;
            if (*mid > x) end = mid;
            else begin = mid + 1;
        }
        return false;
    }

    bool binary_search_trad(std::vector<int> v, const int& x)
    {
        if (!v.size()) return false;
        size_t left = 0;
        size_t right = v.size() - 1;
        size_t mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (v[mid] == x) return true;
            if (v[mid] > x) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
}

int main()
{
    std::vector<int> test {1,2,3,4,5,6,7};
    if (rvn::binary_search(test.begin(), test.end(), 10)) std::cout << "found1" << std::endl;
    if (rvn::binary_search_trad(test, 10)) std::cout << "found2" << std::endl;
    return 0;
}
