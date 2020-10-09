#include "date.h"

vector<string> Month_tbl{"January", "February", "March",
                         "April", "May", "June", "July",
                         "August", "September", "October",
                         "November", "December"};

Month operator++(Month &m)
{
    m = m == Month::Dec ? Month::Jan : Month(int(m) + 1);
    return m;
}

ostream &operator<<(ostream &os, const Month &m)
{
    return os << Month_tbl[int(m) - 1];
}

Date::Date(int year, Month month, int day) : y{year}, m{month}, d{day}
{
    if (!is_valid())
        throw Invalid{};
}

void Date::add_day(int day) {}

bool Date::is_valid()
{
    if (int(m) < 1 || int(m) > 12)
        return false;

    return true;
}