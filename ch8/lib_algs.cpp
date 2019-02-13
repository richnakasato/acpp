#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <unordered_map>
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

    template<class In, class Out, class Pred> Out remove_copy_if(In b, In e, Out d, Pred p)
    {
        while (b != e) {
            if (!p(*b)) {
                *d++ = *b;
            }
            ++b;
        }
        return d;
    }

    template<class In, class Out, class Func> Out transform(In b, In e, Out d, Func f)
    {
        while (b != e) {
            *d++ = f(*b++);
        }
        return d;
    }

    template<class In, class T> T accumulate(In b, In e, const T& x)
    {
        T a = x;
        while (b != e) {
            a += *b++;
        }
        return a;
    }

    template<class In> int distance(In b, In e)
    {
        int c=0;
        while (b++ != e) {
            ++c;
        }
        return c;
    }

    template<class In, class Func> In print(In b, In e, Func f, std::ostream& o)
    {
        while (b != e) {
            o << f(b++);
            if (b != e) o << ", ";
        }
        return b;
    }

    // search(b,e,b2,e2)

    template<class In, class Pred> In find_if(In b, In e, Pred p)
    {
        while (b != e) {
            if (p(*b)) break;
            ++b;
        }
        return b;
    }

    // find_if(b,e,p)

    // remove_copy(b,e,d,t)
    // remove(b,e,t)
    // partition(b,e,p)
}

struct IsNeg {
    bool operator()(const int& x)
    {
        return x < 0;
    }
};

struct DoDouble {
    int operator()(const int& x)
    {
        return 2*x;
    }
};

struct LargeTest {
    LargeTest(const int& n) : n{n} {};
    bool operator()(const int& x)
    {
        return x > n;
    }
private:
    const int n=0;
};

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

    // remove_copy_if
    std::vector<int> test3 {1,-2,3,-4,5,-6,7};
    std::vector<int> test4(test3.size(), 0);
    for (const auto& e : test4) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    std::vector<int>::iterator test4_end = rvn::remove_copy_if(test3.begin(), test3.end(), test4.begin(), IsNeg());
    //rvn::remove_copy_if(test3.begin(), test3.end(), test4.begin(), [](const int& x){ return x<0; });
    for (const auto& e : test4) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    std::cout << rvn::distance(test4.begin(), test4_end);
    std::cout << std::endl;

    // transform
    std::vector<int> test5(test1.size(), 0);
    for (const auto& e : test5) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    //rvn::transform(test1.begin(), test1.end(), test5.begin(), DoDouble());
    rvn::transform(test1.begin(), test1.end(), test5.begin(), [](const int& x){ return 2*x; });
    for (const auto& e : test5) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    // accumulate
    int x = rvn::accumulate(test1.begin(), test1.end(), 0);
    std::cout << x << std::endl;
    x = rvn::accumulate(test1.begin(), test1.end(), 10);
    std::cout << x << std::endl;

    // find
    //std::vector<int>::iterator it = rvn::find_if(test1.begin(), test1.end(), LargeTest(12));
    std::vector<int>::iterator it = rvn::find_if(test1.begin(), test1.end(), [](const int& x){ return x > 12; });
    if (it != test1.end()) std::cout << "found if" << std::endl;
    else std::cout << "not found if" << std::endl;

    // print
    typedef std::vector<int>::iterator t_it;
    rvn::print(test1.begin(), test1.end(), [](t_it it){return *it;}, std::cout);
    std::cout << std::endl;
    std::unordered_map<int,int> test6 {{1,0},
                                       {2,0},
                                       {3,0},
                                       {4,0},
                                       {5,0},
                                       {6,0},
                                       {7,0}};
    typedef std::unordered_map<int,int>::iterator t_mit;
    std::stringstream ss;
    rvn::print(test6.begin(), test6.end(), [](t_mit it){return it->first;}, ss);
    std::cout << ss.str();


    return 0;
}
