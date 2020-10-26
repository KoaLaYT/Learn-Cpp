#include "Mail.h"

#include <fstream>
#include <iostream>

Mail_file::Mail_file(const string& n) : name{n}
{
    ifstream ifs{name};
    if (!ifs) {
        cerr << "Could not open file: " << name << '\n';
        exit(1);
    }

    for (string s; getline(ifs, s);) {
        lines.push_back(s);
    }

    Line_iter first = lines.begin();
    for (Line_iter p = lines.begin(); p != lines.end(); ++p) {
        if (*p == "----") {
            m.push_back(Message{first, p});
            first = p + 1;
        }
    }
}

// is p a prefix of s
int is_prefix(const string& s, const string& p)
{
    int n = p.size();
    if (string(s, 0, n) == p)
        return n;

    return 0;
}

bool find_from_addr(const Message* message, string& name)
{
    for (const auto& line : *message) {
        if (int n = is_prefix(line, "From: ")) {
            name = string(line, n);
            return true;
        }
    }

    return false;
}

string find_subject(const Message* message)
{
    for (const auto& line : *message) {
        if (int n = is_prefix(line, "Subject: ")) {
            return string(line, n);
        }
    }

    return "";
}