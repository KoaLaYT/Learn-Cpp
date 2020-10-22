#include <map>

#include "std_lib_facilities.h"

struct People {
    string name;
    int age;

    bool operator<(const People& other) const
    {
        return name < other.name;
    }
};

int main()
{
    auto byage = [](const People& p1, const People& p2) { return p1.age < p2.age; };
    map<People, double, decltype(byage)> m(byage);
    m.insert({{"Amen", 16}, 1.1});
    m.insert({{"Koalayt", 18}, 1.2});
    m.insert({{"Baby", 12}, 1.3});

    for (const auto& p : m) {
        cout << p.first.name << '(' << p.first.age << "): " << p.second << '\n';
    }

    return 0;
}