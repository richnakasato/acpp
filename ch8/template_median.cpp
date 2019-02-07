#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <class T> T median(std::vector<T> v)
{
    typedef typename std::vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0)
        throw new std::domain_error("median of an empty vector");
    std::sort(v.begin(), v.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

int main()
{
    std::vector<int> test1 {1,2,3,4,5};
    std::vector<double> test2 {1.2, 3.4, 6.7, 6.9};
    std::cout << "test1: " << median(test1) << std::endl;
    std::cout << "test2: " << median(test2) << std::endl;
    return 0;
}
