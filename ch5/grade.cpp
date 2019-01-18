#include <stdexcept>

#include "grade.h"
#include "median.h"

double grade(const double& midterm,
             const double& final_,
             const double& homework)
{
    return 0.2 * midterm + 0.4 * final_ + 0.4 * homework;
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

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final_, s.homeworks);
}

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

std::list<Student_info> extract_fails(std::list<Student_info>& students)
{
    std::list<Student_info> fails;
    std::list<Student_info>::iterator iter = students.begin();
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fails.push_back(*iter);
            iter = students.erase(iter);
        }
        else {
            ++iter;
        }
    }
    return fails;
}
