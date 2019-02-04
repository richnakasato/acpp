#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final_;
    std::vector<double> homeworks;
};

bool compare(const Student_info&, const Student_info&);
bool did_all_homework(const Student_info&);

double median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);
double grade_analysis(const std::vector<Student_info>&,
                      double grade(const Student_info&));

std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

void write_analysis(std::ostream&,
                    const std::string&,
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);

#endif // GUARD_Student_info
