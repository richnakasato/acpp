#include <algorithm>
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
        return grade(midterm, final_, 0.0);
    }
}

double median_grade(const Student_info& s)
{
    return median_grade(s.midterm, s.final_, s.homeworks);
}

double median_grade_aux(const Student_info& s)
{
    return median_grade(s);
}

double average_grade(const double& midterm,
                     const double& final_,
                     const std::vector<double>& homeworks)
{
    try {
        return grade(midterm, final_, average(homeworks));
    }
    catch (std::domain_error) {
        return grade(midterm, final_, 0.0);
    }
}

double average_grade(const Student_info& s)
{
    return average_grade(s.midterm, s.final_, s.homeworks);
}

double average_grade_aux(const Student_info& s)
{
    return average_grade(s);
}

double optimistic_median_grade_aux(const Student_info& s)
{
    std::vector<double> nonzero;
    std::remove_copy(s.homeworks.begin(),
                     s.homeworks.end(),
                     std::back_inserter(nonzero),
                     0.0);
    if (nonzero.empty())
        return grade(s.midterm, s.final_, 0.0);
    else
        return grade(s.midterm, s.final_, median(nonzero));
}

bool fgrade(const Student_info& s)
{
    return median_grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
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

std::vector<Student_info> extract_fails_2p(std::vector<Student_info>& students)
{
    std::vector<Student_info> fails;
    std::remove_copy_if(students.begin(),
                        students.end(),
                        std::back_inserter(fails),
                        pgrade);
    std::vector<Student_info>::iterator it
        = std::remove_if(students.begin(), students.end(), fgrade);
    std::erase(it, students.end());
    return fails;
}

std::vector<Student_info> extract_fails_1p(std::vector<Student_info>& students)
{
    std::vector<Student_info>::iterator it
        = std::stable_partition(students.begin(), students.end(), pgrade);
    std::vector<Student_info> fails(it, students.end());
    std::erase(it, students.end());
    return fails;
}
