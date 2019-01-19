#include <iostream>
#include <string>
#include <vector>

class Student_info {
    std::string n;
    double midterm=0.0, final_=0.0;
    std::vector<double> homeworks;

    double exam_grade() const;
    double homework_grade() const;

public:
    std::istream& read(std::istream&);
    std::string name() const;
    double grade() const;
};
