#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <string>
#include <vector>

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);

    std::istream& read(std::istream&);

    std::string name() const { return name_; }
    double grade() const { return grade_; }

    bool valid() const { return !homeworks_.empty(); }

private:
    std::string name_;
    double midterm_;
    double final_;
    double grade_;
    std::vector<double> homeworks_;

    double exam_grade() const;
    double homework_grade() const;

};

bool compare(const Student_info&, const Student_info&);

#endif // GUARD_student_info_h
