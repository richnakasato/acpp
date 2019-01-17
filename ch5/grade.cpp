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
