#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> dest {"the", "cat", "in", "the", "hat"};
    std::vector<std::string> src {"is", "the", "best", "cat"};

    // old style
    for (std::vector<std::string>::iterator it=dest.begin();
         it != dest.end(); ++it) {

        // testing copying data into another minus 1 element (for backtracking)
        std::vector<std::string> temp;
        std::copy(dest.begin(), it, std::back_inserter(temp));
        std::copy(it+1, dest.end(), std::back_inserter(temp));
        std::cout << "temp..." << std::endl;
        for (const auto& s : temp) {
            std::cout << s << std::endl;
        }

    }

    /* // newer style
    dest.insert(dest.end(), src.begin(), src.end());
    */

    std::copy(src.begin(), src.end(), std::back_inserter(dest));

    for (const auto& s : dest) {
        std::cout << s << std::endl;
    }
    return 0;
}
