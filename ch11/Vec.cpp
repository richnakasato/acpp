template <typename T>
rvn::Vec<T>& rvn::Vec<T>::operator=(const rvn::Vec<T>& rhs)
{
    if (this != &rhs) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}
