#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main()
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;

    std::cout << "Please enter your midterm and final exam grades: ";
    double midterm, final_;
    std::cin >> midterm >> final_;

    std::cout << "Enter all your homework grades, followed by ctrl-d: ";
    double temp;
    std::vector<double> hw_grades {};
    while (std::cin >> temp) {
        hw_grades.push_back(temp);
    }

    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = hw_grades.size();
    if (size == 0) {
        std::cout << "You must enter your grades. "
                     "Please try again." << std::endl;
        return 1;
    }
    std::sort(hw_grades.begin(), hw_grades.end());
    vec_sz mid = size/2;
    double median = mid % 2 == 0 ? (hw_grades[mid] + hw_grades[mid-1]) / 2
                                 : hw_grades[mid];

    double sum = std::accumulate(hw_grades.begin(), hw_grades.end(), 0);

    std::streamsize prev = std::cout.precision();
    std::cout << "Your final grade is " << std::setprecision(3)
              << 0.2 * midterm + 0.4 * final_ + 0.4 * median
              << std::setprecision(prev) << std::endl;



    return 0;
}
