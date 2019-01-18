#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <list>
#include <vector>

#include "Student_info.h"

double grade(const double&, const double&, const double&);
double grade(const double&, const double&, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);
std::list<Student_info> extract_fails(std::list<Student_info>&);

#endif // GUARD_grade_h
