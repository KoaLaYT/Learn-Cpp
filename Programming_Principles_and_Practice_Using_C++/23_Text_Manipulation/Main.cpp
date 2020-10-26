#include <iostream>
#include <map>
#include <string>

#include "Mail.h"

using namespace std;

int main()
{
    Mail_file mfile{"mail.txt"};

    multimap<string, const Message*> sender;

    // build map
    for (const auto& m : mfile) {
        string s;
        if (find_from_addr(&m, s)) {
            sender.insert(make_pair(s, &m));
        }
    }

    // use map
    auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
    for (auto p = pp.first; p != pp.second; ++p) {
        cout << find_subject(p->second) << '\n';
    }

    return 0;
}
