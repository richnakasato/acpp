#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

#include "vector_algs.h"

double median(std::vector<double> v)
{
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0) {
        throw std::domain_error("median of an empty vector");
    }
    std::sort(v.begin(), v.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

double average(std::vector<double>& v)
{
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0) {
        throw std::domain_error("average of an empty vector");
    }
    return std::accumulate(v.begin(), v.end(), 0.0) / size;
}
