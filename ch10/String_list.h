#ifndef GUARD_String_list_h
#define GUARD_String_list_h

#include <list>
#include <string>

namespace rvn {
    class String_list {
        typedef std::list<std::string>::iterator iterator;
        typedef std::list<std::string>::const_iterator const_iterator;
        typedef std::list<std::string>::size_type size_type;

        std::list<std::string> strs;

    public:
        String_list() = default;
        String_list(const int& n, const std::string& s) : strs(n,s) {};

        iterator begin() { return strs.begin(); }
        iterator end() { return strs.end(); }

        const_iterator cbegin() { return strs.cbegin(); }
        const_iterator cend() { return strs.cend(); }

        size_type size() { return strs.size(); }
        bool empty() { return strs.empty(); }

        void push_back(const std::string&);
        void push_front(const std::string&);
    };
}

#endif //GUARD_String_list_h
