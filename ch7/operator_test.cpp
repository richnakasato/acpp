#include <iostream>
#include <stdexcept>
#include <string>


int add(const int& a, const int& b)
{
    return a+b;
}

int sub(const int& a, const int& b)
{
    return a-b;
}

int mul(const int& a, const int& b)
{
    return a*b;
}

int div(const int& a, const int& b)
{
    if (b == 0) throw std::domain_error("div by 0");
    return a/b;
}

int crazy(const int& a, const int& b)
{
    return a*a + b*b + 3;
}

int do_operation(const int& op1, const int& op2, int oper(const int& a,
                                                          const int& b) = add)
{
    return oper(op1, op2);
}

int main()
{
    int a = 10;
    int b = 3;
    std::cout << do_operation(a, b, crazy) << std::endl;
    std::cout << do_operation(a, b, sub) << std::endl;
    std::cout << do_operation(a, b) << std::endl;
    return 0;
}
