#include "std_lib_facilities.h"

int main()
{
    int d;

    cin >> d;

    if (!cin)
    {
        cin.clear();

        char ch;
        while (cin >> ch)
        {
            cout << ch << ' ';
        }
        cout << '\n';
    }

    return 0;
}