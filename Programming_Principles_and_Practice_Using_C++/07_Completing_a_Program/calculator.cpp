#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const char prompt = '>';
const char result = '=';
const char name = 'a';
const char let = 'L';
const string declkey = "let";

class Variable
{
public:
    string name;
    double value;
};

vector<Variable> var_table;

double get_value(string s)
{
    for (const Variable &v : var_table)
    {
        if (v.name == s)
            return v.value;
    }
    error("get: undefined variable: ", s);
}

void set_value(string s, double d)
{
    for (Variable &v : var_table)
    {
        if (v.name == s)
        {
            v.value = d;
            return;
        }
    }
    error("set: undefined variable: ", s);
}

bool is_declared(string s)
{
    for (const Variable &v : var_table)
    {
        if (v.name == s)
            return true;
    }
    return false;
}

double define_name(string s, double d)
{
    if (is_declared(s))
        error(s, " declared twice");

    var_table.push_back(Variable{s, d});
    return d;
}

class Token
{
public:
    char kind;
    double value;
    string name;

    Token(char ch) : kind{ch} {}
    Token(char ch, double d) : kind{ch}, value{d} {}
    Token(char ch, string s) : kind{ch}, name{s} {}
};

class Token_stream
{
public:
    Token get();
    void putback(Token t);
    void ignore(char c);

private:
    bool full{false};
    Token buffer{' '};
};

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch)
    {
    case ';':
    case 'q':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '=':
        return Token{ch};
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{number, val};
    }
    default:
        if (isalpha(ch))
        {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                s += ch;
            cin.putback(ch);
            if (s == declkey)
                return Token{let};
            else
                return Token{name, s};
        }
        error("Bad token");
    }
}

void Token_stream::putback(Token t)
{
    if (full)
        error("putback into a full buffer");

    buffer = t;
    full = true;
}

void Token_stream::ignore(char c)
{
    full = false;

    if (buffer.kind == c)
        return;

    char ch = 0;
    while (cin >> ch)
        if (ch == c)
            return;
}

Token_stream ts;
double expression();

double declaration()
{
    Token t = ts.get();
    if (t.kind != name)
        error("name expected in declaration");

    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in declaration of: ", var_name);

    double d = expression();
    return define_name(var_name, d);
}

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':
    {
        double val = expression();
        t = ts.get();
        if (t.kind != ')')
        {
            error("')' expected");
        }
        return val;
    }
    case number:
        return t.value;
    case '+':
        return primary();
    case '-':
        return -primary();
    case name:
        return get_value(t.name);
    default:
        error("primary expected");
    }
}

double term()
{
    double val = primary();
    while (true)
    {
        Token t = ts.get();
        switch (t.kind)
        {
        case '*':
            val *= primary();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            val /= d;
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            val = fmod(val, d);
            break;
        }
        default:
            ts.putback(t);
            return val;
        }
    }
}

double expression()
{
    double val = term();
    while (true)
    {
        Token t = ts.get();
        switch (t.kind)
        {
        case '+':
            val += term();
            break;
        case '-':
            val -= term();
            break;
        default:
            ts.putback(t);
            return val;
        }
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

void calculate()
{
    while (cin)
    {
        try
        {
            cout << prompt;
            Token t = ts.get();

            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
                return;

            ts.putback(t);
            cout << result << statement() << '\n';
        }
        catch (exception &e)
        {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
}

int main()
{
    try
    {
        calculate();
        return 0;
    }
    catch (exception &e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
}