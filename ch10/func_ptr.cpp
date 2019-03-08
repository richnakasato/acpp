#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Compare {
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs > rhs;
    }
};

struct Compare2 {
    Compare2(int y) : x(y) {}
    bool operator()(const int& v)
    {
        return v > x;
    }
    private:
        int x;
};

template<typename In, typename Pred>
void print_if(In begin, In end, Pred f)
{
    while (begin != end)
    {
        if (f(*begin)) {
            std::cout << *begin << " ";
        }
        ++begin;
    }
    return;
}

int main()
{
    std::vector<int> test {2,3,0,5,8,7,2,9,5,1};
    std::priority_queue<int,std::vector<int>,Compare> pq;
    for (const auto& item : test) {
        pq.push(item);
    }
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
    std::sort(test.begin(), test.end(), Compare());
    for (const auto& item : test) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    print_if(test.begin(), test.end(), Compare2(5));
    std::cout << std::endl;
    print_if(test.begin(), test.end(), [](int x){ return x > 5; });
    std::cout << std::endl;
    return 0;
}
