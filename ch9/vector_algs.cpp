#include "vector_algs.h"

std::istream& read_vector(std::istream& in, std::vector<std::string> v)
{
    std::string elem;
    while(in >> elem) {
        v.push_back(elem);
    }
    return in;
}
