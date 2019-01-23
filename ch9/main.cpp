#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>

#include "Student_info.h"

int main()
{
    std::vector<Student_info> students;
    Student_info temp;
    std::string::size_type maxlen = 0;

    while (temp.read(std::cin)) {
        maxlen = std::max(maxlen, temp.name().size());
        students.push_back(temp);
    }

    std::sort(students.begin(), students.end(), compare);

    for (std::vector<Student_info>::iterator it = students.begin();
         it != students.end();
         ++it) {
        std::cout << it->name();
        std::cout << std::string(maxlen + 1 - it->name().size(), ' ');
        try {
            double final_grade = it->grade();
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade
                      << std::setprecision(prec) << std::endl;
        }
        catch (std::domain_error e) {
            std::cout << e.what() << std::endl;
        }

    }
    return 0;
}
