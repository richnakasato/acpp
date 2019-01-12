#include <iostream>
#include <string>

int main()
{
    // assertion: print numbers 1 - 10, each on a line
    int i = 0;
    while (i < 10) {
        i += 1;
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    // putting 10 - -5 countdown here also...
    for (int i=10; i>-6; --i) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    // also putting product of range [1, 10) here...
    int prod = 1;
    for (int i=1; i<10; ++i) {
        prod *= i;
    }
    std::cout << prod << std::endl;
    std::cout << std::endl;

    // also putting the two number business in here...
    std::cout << "Please enter two numbers: ";
    int left, right;
    std::cin >> left >> right;
    std::string comp;
    if (left > right) {
        comp = ">";
    }
    else if (left < right) {
        comp = "<";
    }
    else {
        comp = "=";
    }
    std::cout << "left " << comp << " right" << std::endl;
    std::cout << std::endl;

    return 0;
}
