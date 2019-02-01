#include <stdexcept>

#include "grade.h"
#include "vector_algs.h"

double grade(const double& midterm,
             const double& final_,
             const double& homework)
{
    return 0.2 * midterm + 0.4 * final_ + 0.4 * homework;
}

double median_grade(const double& midterm,
                    const double& final_,
                    const std::vector<double>& homeworks)
{
    try {
        return grade(midterm, final_, median(homeworks));
    }
    catch (std::domain_error) {
        return grade(s.midterm, s.final_, 0.0);
    }
}

double median_grade(const Student_info& s)
{
    return median_grade(s.midterm, s.final_, s.homeworks);
}

double average_grade(const double& midterm,
                     const double& final_,
                     const std::vector<double>& homeworks)
{
    try {
        return grade(midterm, final_, average(homeworks));
    }
    catch (std::domain_error) {
        return grade(s.midterm, s.final_, 0.0);
    }
}

double average_grade(const Student_info& s)
{
    return average_grade(s.midterm, s.final_, s.homeworks);
}

double grade_aux(const Student_info& s)
{
    try {
        return median_grade(s);
    }
    catch (std::domain_error) {
        return grade(s.midterm, s.final_, 0.0);
    }
}

bool fgrade(const Student_info& s)
{
    return median_grade(s) < 60;
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
