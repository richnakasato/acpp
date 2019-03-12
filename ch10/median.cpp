#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

template <typename Rnd>
double median(Rnd beg, Rnd end)
{
    size_t size = end - beg;
    if (size == 0) {
        throw std::runtime_error("median of empty container");
    }
    std::sort(beg, end);
    size_t mid = size/2;
    return size % 2 == 0 ? (beg[mid-1] + beg[mid])/2.0 : beg[mid];
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    size_t sz_arr = sizeof(arr)/sizeof(*arr);
    std::vector<int> vec(arr, arr+sz_arr);
    assert(median(arr,arr+sz_arr)==median(vec.begin(), vec.end()));
    std::cout << median(arr,arr+sz_arr) << std::endl;
    int arr2[] = {1,2,3,4,5};
    size_t sz_arr2 = sizeof(arr2)/sizeof(*arr2);
    std::cout << median(arr2,arr2+sz_arr2) << std::endl;
    return 0;
}
