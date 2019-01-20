#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <string>
#include <vector>

class Student_info {
    std::string n;
    double midterm=0.0, final_=0.0;
    std::vector<double> homeworks;

    double exam_grade() const;
    double homework_grade();

public:
    std::istream& read(std::istream&);
    std::string name() const { return n; };
    bool valid() const { return !homeworks.empty(); }
    double grade();
};

bool compare(const Student_info&, const Student_info&);

#endif // GUARD_student_info_h
