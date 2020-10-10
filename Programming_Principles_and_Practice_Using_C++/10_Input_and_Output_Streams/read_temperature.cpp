#include "std_lib_facilities.h"

constexpr int not_a_reading = -7777;
constexpr int not_a_month = -1;

vector<string> month_input_table = {"jan", "feb", "mar", "apr", "may", "jun",
                                    "jul", "aug", "sep", "oct", "nov", "dec"};
vector<string> month_output_table = {"January", "February", "March",
                                     "April", "May", "June", "July",
                                     "August", "September", "October",
                                     "November", "December"};

void end_of_loop(istream &is, char term, const string &message)
{
    if (is.fail())
    {
        is.clear();
        char ch;
        if (is >> ch && ch == term)
            return;

        error(message);
    }
}

struct Day
{
    vector<double> readings{vector<double>(24, not_a_reading)};
};

struct Month
{
    int month{not_a_month};
    vector<Day> days{31};
};

struct Year
{
    int year;
    vector<Month> months{12};
};

struct Reading
{
    int day;
    int hour;
    double temperature;
};

bool is_valid(const Reading &r)
{
    if (r.day < 0 || r.day > 30)
        return false;
    if (r.hour < 0 || r.hour > 23)
        return false;
    return true;
}

int month_to_int(const string &m)
{
    for (int i = 0; i < month_input_table.size(); ++i)
    {
        if (month_input_table[i] == m)
            return i;
    }
    error("Invalid month");
}

istream &operator>>(istream &is, Reading &r)
{
    char ch1 = 0;
    if (is >> ch1 && ch1 != '(')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d, h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')')
        error("bad reading");

    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

istream &operator>>(istream &is, Month &m)
{
    char ch1 = 0;
    if (is >> ch1 && ch1 != '{')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month")
        error("bad start of month");

    m.month = month_to_int(mm);

    int duplicate = 0;
    int invalid = 0;
    for (Reading r; is >> r;)
    {
        if (is_valid(r))
        {
            if (m.days[r.day].readings[r.hour] != not_a_reading)
                ++duplicate;
            else
                m.days[r.day].readings[r.hour] = r.temperature;
        }
        else
            ++invalid;
    }
    if (duplicate)
        error("duplicate readings in month ", duplicate);
    if (invalid)
        error("invalid readings in month ", invalid);
    end_of_loop(is, '}', "bad end of month");
    return is;
}

istream &operator>>(istream &is, Year &y)
{
    char ch = 0;
    is >> ch;
    if (ch != '{')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year")
        error("bad start of year");
    y.year = yy;

    while (true)
    {
        Month m;
        if (is >> m)
            y.months[m.month] = m;
        else
            break;
    }
    end_of_loop(is, '}', "bad end of year");
    return is;
}

int main()
{
    cout << "Please enter input file name: \n";
    string iname;
    cin >> iname;
    ifstream ifs{iname};
    if (!ifs)
        error("can't open input file: ", iname);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<Year> ys;

    while (true)
    {
        Year y;
        if (!(ifs >> y))
            break;
        ys.push_back(y);
    }

    cout << "Read " << ys.size() << " data!\n";

    for (const Year &y : ys)
    {
        cout << "Year " << y.year << "\n";
        for (const Month &m : y.months)
        {
            if (m.month == not_a_month)
                continue;

            cout << "\tMonth " << month_output_table[m.month] << '\n';
            for (int i = 0; i < m.days.size(); ++i)
            {
                cout << "\t\tDay " << i + 1 << "\n\t\t\t";
                for (int j = 0; j < m.days[i].readings.size(); ++j)
                {
                    double temp = m.days[i].readings[j];
                    if (temp == not_a_reading)
                        continue;
                    cout << temp;
                    if (j <= m.days[i].readings.size())
                        cout << ", ";
                }
                cout << '\n';
            }
        }
    }

    return 0;
}