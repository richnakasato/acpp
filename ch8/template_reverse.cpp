#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace rvn {
    template<class BidirIt> void reverse(BidirIt begin, BidirIt end)
    {
        while (begin != end) {
            --end;
            if (begin != end)
                std::iter_swap(begin++, end);
        }
    }
    template<class It> std::string print(It begin, It end)
    {
        std::string result;
        std::stringstream ss;
        while (begin != end) {
            ss << *begin++;
            result += ss.str();
            ss.str("");
            ss.clear();
            if (begin != end)
                result += ", ";
        }
        return result;
    }
}

int main()

    std::vector<int> test {1,2,3,4,5,6,7};
    for (const auto& elem : test) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
    rvn::reverse(test.begin(), test.end());
    for (const auto& elem : test) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
    std::string result = rvn::print(test.rbegin(), test.rend());
    std::cout << result << std::endl;
    return 0;
}
