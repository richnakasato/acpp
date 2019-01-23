#include "median.h"
#include "Student_info.h"
#include "vector_algs.h"

Student_info::Student_info() : midterm_{0.0}, final_{0.0}, grade_{0.0} {}

Student_info::Student_info(std::istream& in)
{
    read(in);
}

double Student_info::exam_grade() const
{
    return 0.2 * midterm_ + 0.4 * final_;
}

double Student_info::homework_grade() const
{
    return 0.4 * median(homeworks_);
}

std::istream& Student_info::read(std::istream& in)
{
    in >> name_ >> midterm_ >> final_;
    read_double_vector(in, homeworks_);

    if (valid()) {
        grade_ = exam_grade() + homework_grade();
    }
    else {
        grade_ = exam_grade();
    }

    return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}
