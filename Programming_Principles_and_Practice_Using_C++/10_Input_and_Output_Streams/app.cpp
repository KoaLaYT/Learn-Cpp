#include "std_lib_facilities.h"

int get_int();
int get_int(int low, int high);

int main()
{
    int n = get_int(1, 10);
    cout << n << '\n';
    return 0;
}

void skip_to_int()
{
    if (cin.fail())
    {
        cin.clear();

        for (char c; cin >> c;)
        {
            if (isdigit(c) || c == '-')
            {
                cin.unget();
                return;
            }
        }

        error("no input");
    }
}

int get_int()
{
    int n = 0;
    while (true)
    {
        if (cin >> n)
            return n;
        cout << "Sorry, that was not an integer! Please try again: \n";
        skip_to_int();
    }
}

int get_int(int low, int high)
{
    cout << "Please input an integer between " << low << " and " << high << "(inclusive): \n";
    while (true)
    {
        int n = get_int();
        if (n >= low && n <= high)
            return n;
        cout << "Out of range! Please try again: \n";
    }
}