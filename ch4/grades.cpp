#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final_;
    std::vector<double> homeworks;
};

double grade(const double& midterm,
             const double& final_,
             const double& homework)
{
    return 0.2 * midterm + 0.4 * final_ + 0.4 * homework;
}

double median(std::vector<double> vec)
{
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw std::domain_error("median of an empty vector");
    }
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double grade(const double& midterm,
             const double& final_,
             const std::vector<double>& homework)
{
    if (homework.size() == 0) {
        throw std::domain_error("student has done no homework");
    }
    return grade(midterm, final_, median(homework));
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
    if (in) {
        hw.clear();
        double x;
        while (std::cin >> x) {
            hw.push_back(x);
        }
        in.clear();
    }
    return in;
}

std::istream& read(std::istream& in, Student_info& s)
{
    in >> s.name >> s.midterm >> s.final_;
    read_hw(in, s.homeworks);
    return in;
}

bool compare(const Student_info& left, const Student_info& right)
{
    return left.name < right.name;
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final_, s.homeworks);
}

int main()
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;

    std::cout << "Please enter your midterm and final exam grades: ";
    double midterm, final_;
    std::cin >> midterm >> final_;

    std::cout << "Enter all your homework grades, followed by end-of-file: ";
    std::vector<double> homeworks;
    read_hw(std::cin, homeworks);

    try {
        double final_grade = grade(midterm, final_, homeworks);
        std::streamsize prec = std::cout.precision();
        std::cout << "Your final grade is " << std::setprecision(3)
                  << final_grade << std::setprecision(prec) << std::endl;

    }
    catch (std::domain_error) {
        std::cout << "You must enter your grades. "
                     "Please try again." << std::endl;
        return 1;
    }

    return 0;
}
