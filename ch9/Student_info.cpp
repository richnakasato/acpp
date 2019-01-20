#include "median.h"
#include "Student_info.h"
#include "vector_algs.h"

double Student_info::exam_grade() const
{
    return 0.2 * midterm + 0.4 * final_;
}

double Student_info::homework_grade()
{
    return 0.4 * median(homeworks);
}

std::istream& Student_info::read(std::istream& in)
{
    in >> n >> midterm >> final_;
    read_double_vector(in, homeworks);
    return in;
}

double Student_info::grade()
{
    return exam_grade() + homework_grade();
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}
