#include "Vec.h"

using Line = vector<char>;

class Text_iterator {
    list<Line>::iterator ln;
    Line::iterator pos;

public:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp) : ln{ll}, pos{pp} {}

    char& operator*() { return *pos; }

    Text_iterator& operator++();

    bool operator==(const Text_iterator& other) const
    {
        return ln == other.ln && pos == other.pos;
    }

    bool operator!=(const Text_iterator& other) const
    {
        return !(*this == other);
    }
};

Text_iterator& Text_iterator::operator++()
{
    ++pos;
    if (pos == (*ln).end()) {
        ++ln;
        pos = (*ln).begin();
    }
    return *this;
}

struct Document {
    list<Line> line;

    Document() { line.push_back(Line{}); }

    Text_iterator begin() { return Text_iterator{line.begin(), line.begin()->begin()}; }
    Text_iterator end()
    {
        auto lastline = --line.end();
        return Text_iterator{lastline, lastline->end()};
    }

    void erase_line(int n);
};

istream& operator>>(istream& is, Document& d)
{
    for (char ch; is.get(ch);) {
        d.line.back().push_back(ch);
        if (ch == '\n') {
            d.line.push_back(Line{});
        }
    }
    if (d.line.back().size()) {
        d.line.push_back(Line{});
    }
    return is;
}

void Document::erase_line(int n)
{
    if (n < 0 || n >= line.size() - 1) return;

    auto p = line.begin();
    advance(p, n);
    line.erase(p);
}

bool match(Text_iterator first, Text_iterator last, const string& s)
{
    for (int i = 0; i < s.size(); ++i, ++first) {
        if (first == last || s[i] != *first) return false;
    }
    return true;
}

Text_iterator find_text(Text_iterator first, Text_iterator last, const string& s)
{
    if (s.size() == 0) return last;

    const char c = s[0];

    while (first != last) {
        auto p = find(first, last, c);
        if (p != last && match(p, last, s)) return p;
        ++first;
    }

    return last;
}

int main()
{
    Document d;

    cin >> d;
    for (auto const& c : d) {
        cout << c;
    }
    d.erase_line(0);
    for (auto const& c : d) {
        cout << char(toupper(c));
    }

    auto p = find_text(d.begin(), d.end(), "ha");
    if (p == d.end()) {
        cout << "not found!\n";
    } else {
        cout << "found!\n";
    }

    return 0;
}