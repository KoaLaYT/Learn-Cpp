#include "std_lib_facilities.h"

int main()
{
    int nums[]{1, 2, 3};

    for (int i = 0; i < 3; i++) {
        cout << *(nums + i) << ',';
    }
}