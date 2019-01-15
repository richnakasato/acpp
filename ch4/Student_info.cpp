#include "Student_info.h"

bool compare(const Student_info& left, const Student_info& right)
{
    return left.name < right.name;
}

std::istream& read(std::istream& in, Student_info& s)
{
    std::cout << "Enter name, midterm, final, homeworks, followed by ctrl-d: ";

    in >> s.name >> s.midterm >> s.final_;
    read_hw(in, s.homeworks);

    return in;
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
