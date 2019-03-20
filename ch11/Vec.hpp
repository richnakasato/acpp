namespace rvn {
    template <typename T> class Vec {
    public:
        // interface
        Vec() { create(); }
        explicit Vec(std::size_t n, const T& val=T()) { create(n,val); }
    private:
        // implementation
        T* data;
        T* limit;
    };
}
