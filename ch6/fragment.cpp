#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> u(10, 100);
    std::vector<int> v;
    for (const auto& i : u) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    std::copy(u.begin(), u.end(), std::back_inserter(v));
    for (const auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    return 0;
}
