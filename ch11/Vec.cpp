#include "Vec.hpp"

template <typename T>
rvn::Vec<T>& rvn::Vec<T>::operator=(const rvn::Vec<T>& rhs)
{
    if (this != &rhs) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <typename T>
void rvn::Vec<T>::create()
{
    data = avail = limit = 0;
}

template <typename T>
void rvn::Vec<T>::create(rvn::Vec<T>::size_type n,
                         const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <typename T>
void rvn::Vec<T>::create(rvn::Vec<T>::const_iterator beg,
                         rvn::Vec<T>::const_iterator end)
{
    data = alloc.allocate(end - beg);
    limit = avail = std::uninitialized_copy(beg, end, data);
}
