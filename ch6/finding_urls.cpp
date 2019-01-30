#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

bool not_url_char(char c)
{
    static const std::string url_ch = "~;/?:@=&$-_.+!*'(),";
    return !(isalnum(c) ||
             find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

std::string::const_iterator url_beg(std::string::const_iterator b,
                                    std::string::const_iterator e)
{
}

std::string::const_iterator url_end(std::string::const_iterator b,
                                    std::string::const_iterator e)
{
    return std::find_if(b, e, not_url_char);
}

std::vector<std::string> find_urls(const std::string& str)
{
    std::vector<std::string> result;
    std::string::const_iterator b = str.begin();
    std::string::const_iterator e = str.end();
    while (b != e) {
        b = url_beg(b, e);
        if (b != str.end()) {
            std::string::const_iterator after = url_end(b, e);
            result.push_back(std::string(b, after));
            b = after;
        }
    }
    return result;
}

int main()
{
    return 0;
}
