#include "std_lib_facilities.h"

int main()
{
    for (char c = 'a'; c <= 'z'; c = char(c + 1))
        cout << c << '\t' << int(c) << '\n';
}