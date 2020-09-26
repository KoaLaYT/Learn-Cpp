#include "std_lib_facilities.h"

int main()
{
    cout << "Please input name and age:\n";
    string name;
    double age;
    cin >> name >> age;
    cout << "Hello, " << name << " (age: " << age * 12 << ")\n";
}