#include <algorithm>

#include "grade.h"
#include "Student_info.h"
#include "vector_algs.h"

bool compare(const Student_info& left, const Student_info& right)
{
    return left.name < right.name;
}

bool did_all_homework(const Student_info& s)
{
    return (std::find(s.homeworks.begin(), s.homeworks.end(), 0.0) ==
            s.homeworks.end());
}

double median_analysis(const std::vector<Student_info>& students)
{
    std::vector<double> grades;
    std::transform(students.begin(),
                   students.end(),
                   std::back_inserter(grades),
                   median_grade_aux);
    return median(grades);
}

double average_analysis(const std::vector<Student_info>& students)
{
    std::vector<double> grades;
    std::transform(students.begin(),
                   students.end(),
                   std::back_inserter(grades),
                   average_grade_aux);
    return median(grades);
}

double optimistic_median_analysis(const std::vector<Student_info>& students)
{
    std::vector<double> grades;
    std::transform(students.begin(),
                   students.end(),
                   std::back_inserter(grades),
                   optimistic_median_grade_aux);
    return median(grades);
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

void write_analysis(std::ostream& out,
                    const std::string& name,
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did) <<
                   ", median(didnt) = " << analysis(didnt) << std::endl;
    return;
}
