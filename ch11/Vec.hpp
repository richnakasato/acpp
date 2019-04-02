namespace rvn {
    template <typename T> class Vec {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        typedef T& reference;
        typedef const T& const_reference;

        typedef T value_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;

        // interface
        Vec() { create(); }
        explicit Vec(std::size_t n, const T& t=T()) { create(n, t); }

        Vec(const Vec& v) { create(v.begin(), v.end()); }
        Vec& operator=(const Vec& v);
        ~Vec() { uncreate(); }

        T& operator[](size_type i) { return data[i]; }
        const T& operator[](size_type i) const { return data[i]; }

        void push_back(const T& t)
        {
            if (avail == limit)
                grow();
            unchecked_append(t);
        }

        size_type size() const { return limit - data; }

        iterator begin() { return data; }
        const_iterator begin() const { return data; }

        iterator end() { return limit; }
        const_iterator end() const { return limit; }

    private:
        // implementation
        iterator data;
        iterator avail;
        iterator limit;

        allocator<T> alloc;

        create();
        create(size_type, const T&);
        create(const_iterator, const_iterator);

        void uncreate();

        void grow();
        void unchecked_append(const T&);
    };
}
