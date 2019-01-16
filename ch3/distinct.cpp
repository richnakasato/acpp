#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout << "Please enter a series of words followed by end-of-file: ";
    std::vector<std::string> inputs;
    std::string temp;
    while (std::cin >> temp) {
        inputs.push_back(temp);
    }
    std::sort(inputs.begin(), inputs.end());
    int count = 0;
    int total = 0;
    temp = "";
    for (const auto& s : inputs) {
        ++total;
        if (temp == "") {
            temp = s;
            count = 1;
        }
        else {
            if (temp != s) {
                std::cout << temp << ": " << count << std::endl;
                temp = s;
                count = 1;
            }
            else {
                ++count;
            }
        }
    }
    std::cout << temp << ": " << count << std::endl;
    std::cout << "total words: " << total << std::endl;

    return 0;
}
