#include "std_lib_facilities.h"
#include "date.h"

int main()
{
    Date today{2020, Month::Oct, 9};

    cout << today.month() << '\n';

    try
    {
        Date tomorrow{2020, Month::Dec, 12};
    }
    catch (Date::Invalid)
    {
        cout << "Invalid Date!\n";
    }

    Month m = Month::Nov;
    cout << m << '\n';
    ++m;
    cout << m << '\n';
    ++m;
    cout << m << '\n';

    return 0;
}