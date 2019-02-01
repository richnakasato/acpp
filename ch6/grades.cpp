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
    std::vector<Student_info> did, didnt;
    Student_info record;
    std::string::size_type max_len = 0;

    while (read(std::cin, record)) {
        max_len = std::max(max_len, record.name.size());
        if (did_all_homework(record)) {
            did.push_back(record);
            return 1;
        }
        else {
            didnt.push_back(record);
            return 1;
        }
    }

    if (did.empty())
        std::cout << "No student did all homeworks!" << std::endl;
    if (didnt.empty())
        std::cout << "Every student did all homeworks!" << std::endl;

    write_analysis(std::cout, "median", median_analysis, did, didnt);
    write_analysis(std::cout, "average", average_analysis, did, didnt);
    write_analysis(std::cout,
                   "median of homework turned in",
                   optimistic_median_analysis,
                   did,
                   didnt);

    return 0;
}
