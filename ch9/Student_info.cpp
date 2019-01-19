#include "Student_info.h"
#include "vector_algs.h"

double Student_info::exam_grade() const
{
    return 0.2 * midterm + 0.4 * final_;
}

double Student_info::homework_grade() const
{
    return 1.0;
}

std::istream& Student_info::read(std::istream& in)
{
    in >> n >> midterm >> final_;
    return in;
}

std::string Student_info::name() const
{
    return n;
}

double Student_info::grade() const
{
    return exam_grade() + homework_grade();
}

int main()
{
    Student_info record;
    record.read(std::cin);
    std::cout << record.name();
    std::cout << record.grade();
    return 0;
}
