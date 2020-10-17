#include "Vec.h"

Vec<int> build_vec(int n) {
    Vec<int> v(n);
    return v;
}

int main()
{
    Vec<int> v = build_vec(3);
    v.print();
    v[0]=3;
    v.push_back(1);
    v.print();
    return 0;
}