#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final_;
    std::vector<double> homeworks;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);

#endif // GUARD_Student_info
