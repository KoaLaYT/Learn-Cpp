#include "std_lib_facilities.h"

class Vec {
public:
    // constructor variant #1
    explicit Vec(int s) : sz{s}, elem{new double[s]}
    {
        for (int i = 0; i < s; ++i) elem[i] = 0.0;
    }
    // constructor variant #2
    Vec(initializer_list<double> lst) : sz{int(lst.size())}, elem{new double[sz]}
    {
        copy(lst.begin(), lst.end(), elem);
    }
    // default constructor
    Vec() : Vec(0) {}
    // copy constructor
    Vec(const Vec& other) : sz{other.sz}, elem{new double[sz]}
    {
        copy(other.elem, other.elem + sz, elem);
    }
    // copy assignment
    Vec& operator=(const Vec& other)
    {
        if (&other == this) return *this;

        sz = other.sz;
        delete[] elem;
        elem = new double[sz];
        copy(other.elem, other.elem + sz, elem);
        return *this;
    }
    // move constructor
    Vec(Vec&& other) : sz{other.sz}, elem{other.elem}
    {
        other.elem = nullptr;
        other.sz = 0;
    }
    // move assignment
    Vec& operator=(Vec&& other)
    {
        delete[] elem;
        sz = other.sz;
        elem = other.elem;

        other.sz = 0;
        other.elem = nullptr;

        return *this;
    }
    // destructor
    ~Vec() { delete[] elem; }

    int size() const { return sz; }
    double get(int i) const { return elem[i]; }
    void set(int i, double d) { elem[i] = d; }
    double& operator[](int i) { return elem[i]; }
    double operator[](int i) const { return elem[i]; }

    void print() const
    {
        for (int i = 0; i < size(); ++i) {
            if (i > 0) cout << ", ";
            cout << elem[i];
        }
        cout << '\n';
    }

private:
    int sz;
    double* elem;
};

int main()
{
    Vec v{1.1, 2.2, 3.3};
    cout << "v: ";
    v.print();
    Vec vc{v};
    cout << "vc: ";
    vc.print();

    v[0] = 4.4;
    vc[1] = 4.4;
    cout << "after modified v\n";
    cout << "v: ";
    v.print();
    cout << "vc: ";
    vc.print();

    vc = v;
    cout << "after assignment\n";
    v.print();
    vc.print();

    v[0] = 1.1;
    vc[1] = 1.1;
    cout << "after modified v\n";
    cout << "v: ";
    v.print();
    cout << "vc: ";
    vc.print();

    vc = vc;
    vc.print();

    return 0;
}