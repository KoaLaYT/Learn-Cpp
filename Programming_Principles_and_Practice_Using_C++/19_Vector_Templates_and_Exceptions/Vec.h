#ifndef VEC_H_2020_10_16
#define VEC_H_2020_10_16

#include "std_lib_facilities.h"

template <typename T, typename A = allocator<T>>
class Vec {
public:
    // constructor variant #1
    explicit Vec(int s, T def = T());
    // constructor variant #2
    Vec(initializer_list<T> lst);
    // default constructor
    Vec() : sz{0}, elem{nullptr}, space{0} {}
    // copy constructor
    Vec(const Vec& other);
    // copy assignment
    Vec& operator=(const Vec& other);
    // move constructor
    Vec(Vec&& other);
    // move assignment
    Vec& operator=(Vec&& other);
    // destructor
    ~Vec() { alloc.deallocate(elem, space); }

    int size() const { return sz; }
    int capacity() const { return space; }
    T get(int i) const { return elem[i]; }
    void set(int i, T d) { elem[i] = d; }
    T& operator[](int i) { return elem[i]; }
    T operator[](int i) const { return elem[i]; }

    void push_back(const T& d);
    void reserve(int newalloc);
    void resize(int size, T def = T());
    void print() const;

private:
    int sz;
    T* elem;
    int space;
    A alloc;
};

// constructor variant #1
template <typename T, typename A>
Vec<T, A>::Vec(int s, T def) : sz{s}, space{s}
{
    elem = alloc.allocate(sz);
    for (int i = 0; i < sz; ++i)
        alloc.construct(&elem[i], def);
}
// constructor variant #2
template <typename T, typename A>
Vec<T, A>::Vec(initializer_list<T> lst) : sz{int(lst.size())}, space{sz}
{
    elem = alloc.allocate(sz);
    int i = 0;
    for (const T& e : lst)
        alloc.construct(&elem[i++], e);
}
// copy constructor
template <typename T, typename A>
Vec<T, A>::Vec(const Vec<T, A>& other) : sz{other.sz}, space{sz}
{
    elem = alloc.allocate(sz);
    for (int i = 0; i < sz; ++i)
        alloc.construct(&elem[i], other.elem[i]);
}
// copy assignment
template <typename T, typename A>
Vec<T, A>& Vec<T, A>::operator=(const Vec<T, A>& other)
{
    if (&other == this) return *this;

    if (other.sz <= space) {
        for (int i = 0; i < other.sz; ++i) {
            alloc.destroy(&elem[i]);
            alloc.construct(&elem[i], other.elem[i]);
        }
        for (int i = sz; i < other.sz; ++i) {
            alloc.destroy(&elem[i]);
        }
        sz = other.sz;
        return *this;
    }

    T* p = alloc.allocate(other.sz);
    for (int i = 0; i < other.sz; ++i) {
        alloc.construct(&p[i], other.elem[i]);
    }
    for (int i = 0; i < sz; ++i) {
        alloc.destroy(&elem[i]);
    }
    alloc.deallocate(elem, space);
    space = sz = other.sz;
    elem = p;
    return *this;
}
// move constructor
template <typename T, typename A>
Vec<T, A>::Vec(Vec<T, A>&& other) : sz{other.sz}, elem{other.elem}, space{other.space}
{
    other.elem = nullptr;
    other.space = other.sz = 0;
}
// move assignment
template <typename T, typename A>
Vec<T, A>& Vec<T, A>::operator=(Vec<T, A>&& other)
{
    for (int i = 0; i < sz; ++i) {
        alloc.destroy(&elem[i]);
    }
    alloc.deallocate(elem, space);
    space = sz = other.sz;
    elem = other.elem;

    other.space = other.sz = 0;
    other.elem = nullptr;

    return *this;
}

template <typename T, typename A>
void Vec<T, A>::print() const
{
    for (int i = 0; i < size(); ++i) {
        if (i > 0) cout << ", ";
        cout << elem[i];
    }
    cout << '\n';
}

template <typename T, typename A>
void Vec<T, A>::reserve(int newalloc)
{
    if (newalloc <= space) return;

    T* p = alloc.allocate(newalloc);
    for (int i = 0; i < sz; ++i)
        alloc.construct(&p[i], elem[i]);
    for (int i = 0; i < sz; ++i)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem, space);
    elem = p;
    space = newalloc;
}

template <typename T, typename A>
void Vec<T, A>::resize(int newsize, T def)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
        alloc.construct(&elem[i], def);
    for (int i = newsize; i < sz; ++i)
        alloc.destroy(&elem[i]);
    sz = newsize;
}

template <typename T, typename A>
void Vec<T, A>::push_back(const T& d)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(space * 2);

    alloc.construct(&elem[sz], d);
    ++sz;
}

#endif