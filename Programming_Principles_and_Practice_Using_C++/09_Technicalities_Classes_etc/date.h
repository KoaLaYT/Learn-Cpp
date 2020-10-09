#ifndef DATE_2020_12_09_H
#define DATE_2020_12_09_H
#include "std_lib_facilities.h"

enum class Month
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};

Month operator++(Month &m);
ostream &operator<<(ostream &os, const Month &m);

class Date
{
public:
    class Invalid
    {
    };

    Date(int year, Month month, int day);

    void add_day(int day);

    int year() { return y; }
    Month month() { return m; }
    int day() { return d; }

private:
    int y, d;
    Month m;
    bool is_valid();
};

#endif