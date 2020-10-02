#include "std_lib_facilities.h"

class Token
{
public:
    char kind;
    double value;
};

class Token_stream
{
public:
    Token get();
    void putback(Token t);

private:
    bool full{false};
    Token buffer;
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
        return Token{'8', val};
    }
    default:
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

Token_stream ts;
double expression();

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
    case '8':
        return t.value;
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
            val /= primary();
            break;
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

int main()
{
    try
    {
        double val = 0;
        while (cin)
        {
            Token t = ts.get();
            switch (t.kind)
            {
            case 'q':
                return 0;
            case ';':
                cout << "=" << val << '\n';
                break;
            default:
                ts.putback(t);
                val = expression();
            }
        }
    }
    catch (exception &e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "exception\n";
        return 2;
    }
}