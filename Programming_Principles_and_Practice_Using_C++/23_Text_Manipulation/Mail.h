#ifndef MAIL_H_2020_10_24
#define MAIL_H_2020_10_24

#include <string>
#include <vector>

using namespace std;

using Line_iter = vector<string>::const_iterator;

class Message {
public:
    Message(Line_iter f, Line_iter l) : first{f}, last{l} {}
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }

private:
    Line_iter first;
    Line_iter last;
};

using Mess_iter = vector<Message>::const_iterator;

class Mail_file {
public:
    Mail_file(const string& n);
    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }

private:
    string name;
    vector<string> lines;
    vector<Message> m;
};

// find the name of the sender in a message
// return true if found
// if found, place the name in s
bool find_from_addr(const Message*, string&);

// return the subject of the message, if any, otherwise ""
string find_subject(const Message*);

#endif