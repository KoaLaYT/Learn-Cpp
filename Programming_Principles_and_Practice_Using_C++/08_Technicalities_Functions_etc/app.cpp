#include "std_lib_facilities.h"

const string &greet()
{
    static const string s = "hello";
    return s;
}

int main()
{
    const string &s = greet();

    cout << s << '\n';

    return 0;
}