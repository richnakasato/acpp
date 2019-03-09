#include <iostream>
#include <string>

std::string letter_grade(const double& grade)
{
    // static means do once, on first call,
    // const is will not change after being set
    static const double numbers[] = {97, 94, 90,
                                     87, 84, 80,
                                     77, 74, 70,
                                     60, 0};
    static const char* const letters[] = {"A+", "A", "A-",
                                          "B+", "B", "B-",
                                          "C+", "C", "C-",
                                          "D", "F"};
    static const int ngrades = sizeof(numbers)/sizeof(*numbers);

    for (size_t i=0; i<ngrades; ++i) {
        if (grade >= numbers[i]) return letters[i];
    }
    return "?\?\?";
}

int main()
{
    std::cout << "input a letter grade:\n";
    double input;
    while (std::cin >> input) {
        std::cout << letter_grade(input) << "\n";
    }
    return 0;
}
