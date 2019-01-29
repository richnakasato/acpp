#include <string>
#include <vector>

std::vector<std::string> find_urls(const std::string& str)
{
    std::vector<std::string> result;
    std::string::const_iterator b = str.begin();
    std::string::const_iterator e = str.end();
    while (b != e) {
        b = url_beg(b, e);
    }
    return result;
}

int main()
{
    return 0;
}
