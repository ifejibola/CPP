#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <sstream>
// #include <table.h>
using namespace std;
/*
    * CALCULATOR CONSISTS OF : FOUR MAIN PARTS
        * A PARSER : Responsible for the syntactic analysis.
        * 
        * Input FUNCTION : Handles input and lexical analysis
        * 
        * SYMBOL TABLE : Holds permanent information
        * 
        * DRIVER : Handles initialization, output, and errors.
        * 
    
    * FOR INPUT : THE PARSER : uses a Token_stream that encapsulates the reading characters
                    and their composition into Tokens. That is Token_stream "tokenizes":
                    It turns streams of characters such as 123.45 into Tokens.
                : Token : a token is a {Kind-of-token, value} pair. such as {number, 123.45}

    - Parser need only to know the name of the Token_stream, ts, and how to get Tokens from it.
    - To read next Token, it calls ts.get().
    - To get the most recently read Token(the "current token"), it calls ts.current(). 

    - In addition to tokenizing, the Token_stream hides the actual source of the characters.
*/

// Define Token
enum class Kind : char
{
    name,
    number,
    end,
    plus = '+',
    minus = '-',
    mul = '*',
    div = '/',
    print = ';',
    assign = '=',
    lp = '(',
    rp = ')'
};

struct Token
{
    Kind kind;
    string string_value;
    double number_value;
};

// Interface to Token_stream

class Token_stream
{
public:
    Token_stream(istream &s) : ip{&s}, owns{false} {}
    Token_stream(istream *p) : ip{p}, owns{true} {}

    Token_stream() { close(); }
    Token get();            // read and return next token
    const Token &current(); // most recently read token

    void set_input(istream &s)
    {
        close();
        ip = &s;
        owns = false;
    };
    void set_input(istream *p)
    {
        close();
        ip = p;
        owns = true;
    };

private:
    void close()
    {
        if (owns)
            delete ip;
    };

    istream *ip;         //pointer to an input stream
    bool owns;           // does the Token_stream own the istream?
    Token ct{Kind::end}; // current token
};
map<string, double> table;

//The Driver
Token_stream ts{cin}; //use input from cin

// Error handling
// Counts the errors, writes out an error message, and returns

int no_of_errors;
double error(const string &s)
{
    no_of_errors++;

    cerr << "error: " << s << '\n';
    return 1;
};

Token Token_stream::get()
{
    char ch = 0;
    *ip >> ch;

    do
    {
        // skip whitespace except '\n'
        if (!ip->get(ch))
            return ct = {Kind::end};
    } while (ch != '\n' && isspace(ch));

    switch (ch)
    {
    case 0:
        return ct = {Kind::end}; // assign and return
    case ';':
    case '\n':
        return ct = {Kind::print};
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
        return ct = {static_cast<Kind>(ch)};
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
    case '.':
        ip->putback(ch);        // put the first digit(or .) back into the input stream
        *ip >> ct.number_value; // read number into ct
        ct.kind = Kind::number;
        return ct;

    default: // name, name=, or error
        if (isalpha(ch))
        {
            ip->putback(ch);        // put the first character back into the input stream
            *ip >> ct.string_value; // read string into ct
            ct.kind = Kind::name;
            return ct;
        };

        error("bad token");
        return ct = {Kind::print};
    };
}

double expr(double);

double prim(bool get) // handle primaries
{
    if (get)
        ts.get(); // read next token

    switch (ts.current().kind)
    {
    case Kind::number: // floating-point constant
    {
        double v = ts.current().number_value;
        ts.get();
        return v;
    }
    case Kind::name:
    {
        double &v = table[ts.current().string_value]; // find the corresponding
        if (ts.get().kind == Kind::assign)
            v = expr(true); // '=' seen: assignment
        return v;
    }
    case Kind::minus: // unary minus
        return -prim(true);

    case Kind::lp:
    {
        auto e = expr(true);
        if (ts.current().kind != Kind::rp)
            return error("')' expected");
        ts.get(); // eat ')'
        return e;
    }
    default:
        return error("primary expected");
    };
};
// double expr(double);

double term(bool get) // multiply and divide
{
    double left = prim(get);

    for (;;)
    {
        switch (ts.current().kind)
        {
        case Kind::mul:
            left *= prim(true);
            break;

        case Kind::div:
            /*
            The result of dividing by zero is undefined and usually disastrous.
             We therefore test for 0 before dividing and call error() if we detect a zero divisor.

            * The variable d is introduced into the program exactly where it is needed and initialized immedi- ately.
             
        */
            if (auto d = prim(true))
            {
                left /= d;
                break;
            }
            return error("divide by 0");

        default:
            return left;
        }
    }
}

double expr(bool get) // add and subtract
{
    double left = term(get);
    // The curious notation for(;;) is a way to specify an infinite loop; while(true) in an alternative.
    for (;;) // forever;
    {
        /*
            * The switch-statement is executed repeatedly until some-thing different from 
            + and - is found, and then the return-statement in the default case is executed.
        */
        switch (ts.current().kind)
        {
        case Kind::plus:
            left += term(true);
            break;
        case Kind::minus:
            left -= term(true);
            break;
        default:
            return left;
        }
    }

    /*
        * This function really does not do much itself. 
        In a manner typical of higher-level functions in a large program, 
        it calls other functions to do the work.
    */
}

/*
    * The stream cerr is an unbuffered output stream usuall used to report errors
*/

void calculate()
{
    for (;;)
    {
        ts.get();
        if (ts.current().kind == Kind ::end)
            break;
        if (ts.current().kind == Kind ::print)
            continue;
        cout << expr(false) << '\n';
    };
};

int main(int argc, char *argv[])
{

    switch (argc)
    {
    case 1: // Read from standard input
        break;
    case 2: // read from argument string
        ts.set_input(new istringstream{argv[1]});
        break;
    default:
        error("Too many arguments");
        return 1;
    }
    table["pi"] = 3.1415926535897932385; // insert predefined names
    table["e"] = 2.7182818284590452354;

    calculate();
    return no_of_errors;
};