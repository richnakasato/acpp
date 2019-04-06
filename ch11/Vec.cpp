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

template <typename T>
void rvn::Vec<T>::uncreate()
{
    if (data) {
        iterator it = avail;
        while (it != data) {
            alloc.destroy(--it);
        }
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

template <typename T>
void rvn::Vec<T>::grow()
{
    size_type new_sz = max((limit - data) * 2, ptrdiff_t(1));
    iterator temp_data = alloc.allocate(new_sz);
    iterator temp_avail = std::uninitialized_copy(data, limit, temp_data);
    uncreate();
    data = temp_data;
    avail = temp_avail;
    limit = data + new_sz;
}

template <typename T>
void rvn::Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}
