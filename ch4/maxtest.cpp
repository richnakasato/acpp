#include <algorithm>

#include "Student_info.h"

int main()
{
    std::string::size_type maxlen;
    Student_info s;
    std::max(maxlen, s.name.size());
    return 0;
}
