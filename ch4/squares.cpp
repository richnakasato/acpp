#include <iomanip>
#include <iostream>

int main()
{
    double maxsq = 999.0;
    for (double i=1.0; i<=maxsq; ++i) {
        std::cout << i << ": " << std::setw(10) << i*i << std::endl;
    }
    return 0;
}
