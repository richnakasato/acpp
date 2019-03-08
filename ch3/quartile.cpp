#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout << "Please enter a series of integers then end-of-file: ";
    std::vector<int> ints;
    int temp;
    while (std::cin >> temp) {
        ints.push_back(temp);
    }
    std::sort(ints.begin(), ints.end());
    return 0;
}
