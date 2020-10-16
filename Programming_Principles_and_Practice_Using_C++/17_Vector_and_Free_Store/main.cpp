#include "std_lib_facilities.h"

int main()
{
    int* ds = new int[4]{1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        cout << "d[" << i << "]=" << ds[i] << ", ";
    }
    cout << '\n';
    cout << "d[-1]=" << *(ds - 1) << '\n';
    return 0;
}