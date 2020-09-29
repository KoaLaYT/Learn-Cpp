#include "std_lib_facilities.h"

int main()
{
    cout << "Please input a number followed by unit(i or c):\n";
    double number = 0.0;
    char unit = 'a';
    cin >> number >> unit;

    switch (unit)
    {
    case 'c':
        cout << number << ' ' << unit;
        break;
    case 'i':
        cout << unit << ' ' << number;
        break;
    default:
        cout << "What's this? " << number << unit;
        break;
    }
}