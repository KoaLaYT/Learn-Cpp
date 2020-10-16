#include "std_lib_facilities.h"

bool is_palindrome_v1(const string& s)
{
    int head = 0;
    int tail = s.size() - 1;
    while (head < tail) {
        if (s[head] != s[tail]) return false;
        ++head;
        --tail;
    }
    return true;
}

void check(const string& s)
{
    if (is_palindrome_v1(s))
        cout << s << " is palindrome\n";
    else
        cout << s << " is not palindrome\n";
}

int main()
{
    check("malayalam");
    check("homesick");
}