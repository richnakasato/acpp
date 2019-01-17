#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"

int main()
{
    std::vector<Student_info> students;
    Student_info record;
    std::string::size_type max_len = 0;
    while (read(std::cin, record)) {
        max_len = std::max(max_len, record.name.size());
        students.push_back(record);
    }

    std::sort(students.begin(), students.end(), compare);
    for (std::vector<Student_info>::size_type i=0; i!=students.size(); ++i) {
        std::cout << students[i].name
                  << std::string(max_len+1-students[i].name.size(), ' ');
        try {
            double final_grade = grade(students[i]);
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade
                      << std::setprecision(prec) << std::endl;
        }
        catch (std::domain_error e){
            std::cout << e.what();
            return 1;
        }
    }
    return 0;
}
