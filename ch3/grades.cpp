#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

void print_error()
{
    std::cout << "Did not enter the correct number of values! "
                 "Please try again." << std::endl;
}

int main()
{
    std::cout << "Please enter each students name (end with 'x'): ";
    std::vector<std::string> names;
    std::string name;
    while (std::cin >> name) {
        if (name == "x") {
            break;
        }
        names.push_back(name);
    }

    std::vector<std::string>::size_type names_sz = names.size();
    if (names_sz == 0) {
        print_error();
        return 1;
    }

    std::vector<std::vector<double>> all_grades;
    for (const auto& name : names) {
        std::vector<double> grades;

        std::cout << "Please enter " << name << "'s "
                     "midterm and final grades: ";
        double midterm, final_;
        std::cin >> midterm >> final_;
        grades.push_back(midterm);
        grades.push_back(final_);

        std::cout << "Please enter " << name << "'s "
                     "four homework grades: ";
        double hw1, hw2, hw3, hw4;
        std::cin >> hw1 >> hw2 >> hw3 >> hw4;
        grades.push_back(hw1);
        grades.push_back(hw2);
        grades.push_back(hw3);
        grades.push_back(hw4);

        all_grades.push_back(grades);
        std::cout << std::endl;
    }

    int student_idx = 0;
    for (auto& grades : all_grades) {
        std::sort(grades.begin()+2, grades.end());
        double midterm = grades[0];
        double final_ = grades[1];
        double median = (grades[3] + grades[4])/2;

        std::streamsize prev = std::cout.precision();
        std::cout << names[student_idx] << "'s final grade is "
                  << std::setprecision(3)
                  << 0.2 * midterm + 0.4 * final_ + 0.4 * median
                  << std::setprecision(prev) << std::endl;
        ++student_idx;
    }

    return 0;
}
