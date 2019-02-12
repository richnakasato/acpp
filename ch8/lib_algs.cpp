#include <iostream>
#include <string>
#include <vector>

namespace rvn
{
    template<class In> bool equal(In b, In e, In d)
    {
        while (b != e) {
            if (*b != *d) return false;
            ++b;
            ++d;
        }
        return true;
    }

    template<class In, class X> bool find(In b, In e, const X& x)
    {
        while (b != e) {
            if (*b++ == x) return true;
        }
        return false;
    }

    template<class In, class Out> Out copy(In b, In e, Out d)
    {
        while (b != e) {
            *d++ = *b++;
        }
        return d;
    }

    // remove_copy_if(b,e,d,p)
    // transform(b,e,d,f)
    // accumulate(b,e,t)
    // search(b,e,b2,e2)
    // find_if(b,e,p)
    // remove_copy(b,e,d,t)
    // remove(b,e,t)
    // partition(b,e,p)
}

int main()
{
    std::vector<int> test1 {1,2,3,4,5,6,7};
    std::vector<int> test2 {1,2,3,4,5,6,7};

    // equal
    if (rvn::equal(test1.begin(), test1.end(), test2.begin()))
        std::cout << "equal" << std::endl;
    else
        std::cout << "not equal" << std::endl;

    // find
    if (rvn::find(test1.begin(), test1.end(), 4))
        std::cout << "found" << std::endl;
    else
        std::cout << "not found" << std::endl;


    return 0;
}
