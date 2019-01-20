#include "vector_algs.h"

std::istream& read_double_vector(std::istream& in, std::vector<double>& v)
{
    if (in) {
        v.clear();
        double temp;
        while (in >> temp) { v.push_back(temp); }
        in.clear();
    }
    return in;
}
