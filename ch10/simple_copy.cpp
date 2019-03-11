#include <fstream>
#include <string>

int main()
{
    std::ifstream infile("test_in.txt");
    std::ofstream outfile("test_out.txt");
    std::string s;
    while (getline(infile, s)) {
        outfile << s << std::endl;
    }
    return 0;
}
