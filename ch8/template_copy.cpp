#include <iostream>
#include <string>
#include <vector>

template<class In, class Out> Out my_copy(const In& begin, const In& end, Out dst)
{
    while (begin != end)
        *(dst++) = *(begin++);
    return dst;
}

int main()
{
    std::vector<int> src {1,2,3,4,5};
    std::vector<int> dst(5, 0);
    for (const auto& num : src) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    for (const auto& num : dst) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    copy(src.begin(), src.end(), dst.begin());
    for (const auto& num : dst) {
        std::cout << num << " ";
    }
    return 0;
}
