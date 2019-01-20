#include <iostream>

#include "Student_info.h"

int main()
{
    Student_info record;
    record.read(std::cin);
    std::cout << record.name() << ": " << record.grade();
    return 0;
}
