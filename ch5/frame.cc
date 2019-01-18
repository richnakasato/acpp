#include <algorithm>

#include "frame.h"

std::string::size_type width(const std::vector<std::string>& v)
{
    typedef std::string::size_type str_sz;
    typedef std::vector<std::string>::size_type vec_sz;

    str_sz maxlen = 0;
    for (vec_sz i = 0; i != v.size(); ++i) {
        maxlen = std::max(maxlen, v[i].size());
    }
    return maxlen;
}

std::vector<std::string> frame(const std::vector<std::string>& v)
{
    typedef std::string::size_type str_sz;
    typedef std::vector<std::string>::size_type vec_sz;

    std::vector<std::string> ret;
    str_sz maxlen = width(v);
    std::string border(maxlen + 4, '*');

    ret.push_back(border);
    for (vec_sz i=0; i!=v.size(); ++i) {
        std::string word = v[i];
        std::string buffer = string(maxlen-word.size(), ' ');
        ret.push_back("* " + word + buffer + " *");
    }
    ret.push_back(border);

    return ret;
}

std::vector<std::string> vcat(const std::vector<std::string>& top,
                              const std::vector<std::string>& bottom)
{
    std::vector<std::string> ret = top;
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}

std::vector<std::string> hcat(const std::vector<std::string>& left,
                              const std::vector<std::string>& right)
{
    typedef std::string::size_type str_sz;
    typedef std::vector<std::string>::size_type vec_sz;

    std::vector<std::string> ret;
    str_sz width1 = width(left) + 1;
    vec_sz i = 0, j = 0;

    while (i != left.size() || j != right.size()) {
        std::string s;
        if (i != left.size()) {
            s = left[i++];
        }
        s += string(width1 - s.size(), ' ');
        if (j != right.size()) {
            s += right[j++];
        }
        ret.push_back(s);
    }
    return ret;
}
