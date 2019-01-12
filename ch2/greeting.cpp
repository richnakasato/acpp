#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    std::cout << std::endl;

    std::cout << "Please enter greeting pad size: ";
    int pad;
    std::cin >> pad;
    std::cout << std::endl;

    const std::string greeting = "Hello, " + name + "!";

    const int pad_r = pad;
    const int rows = pad_r * 2 + 3;

    for (int r=0; r<rows; ++r) {

        const int pad_c = pad;
        const std::string::size_type space_count = greeting.size() + pad_c * 2;
        const std::string::size_type cols = space_count + 2;
        const std::string spaces(space_count, ' ');

        std::string::size_type c = 0;
        while (c<cols) {
            if (r == pad_r+1 && c == pad_c+1) {
                std::cout << greeting;
                c+=greeting.size();
            }
            else {
                if (r == 0 || r == rows-1 || c == 0 || c == cols-1) {
                    std::cout << "*";
                    ++c;
                }
                else if (r == pad_r+1) {
                    std::cout << " ";
                    ++c;
                }
                else {
                    std::cout << spaces;
                    c+=space_count;
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
