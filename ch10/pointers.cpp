#include <iostream>
#include <string>

int add(int lhs, int rhs)
{
    return lhs + rhs;
}

int sub(int lhs, int rhs)
{
    return lhs - rhs;
}

int do_oper(int lhs, int rhs, int oper(int,int) = add)
{
    return oper(lhs, rhs);
}

int main()
{
    int x = 5;
    std::cout << x << std::endl;

    int* p = &x;
    *p = 6;
    std::cout << x << std::endl;

    std::cout << do_oper(5, 6) << std::endl;
    std::cout << do_oper(5, 6, sub) << std::endl;

    return 0;
}
