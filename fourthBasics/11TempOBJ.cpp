using namespace std;
#include <iostream>

/*
    * Often the compiler mustr introduce an object to hold an intermediate result of an expression.
    * E.G v=x+y*z; the result of y*Z has ot be put somewhere before it is added to x.
    * Handles automatically for built-ins 
    * But for user defined types: knowing the lifetime of a temp can be important.
    * 
    * A full expression is an expression that is not a subexpression of some other expression.
    * 
    * The standard-lib string has a member c_str() : Returns a C-Style pointer to a zero-terminated
    * array of chars
    * 
    * The + operator is defined to mean string concatenation : However in combination they can 
    * cause obsure problems. FOR EXAMPLE:
*/
//will work but with issues
void tempObj(string &s1, string &s2, string &s3)
{
    const char *cs = (s1 + s2).c_str();
    cout << cs;
    if (strlen(cs = (s2 + s3).c_str()) < 8 && cs[0] == 'a')
    {
        // cs used here
    }
};

//will work, no issues ( best used when try to display temp data that doesnt need to be saved)
void temObj2(string &s1, string &s2, string &s3)
{
    cout << s1 + s2;
    string s = s2 + s3;

    if (s.length() < 8 && s[0] == 'a')
    {
        // use s here
    }
};

// A temp can be used as an initializer for a const reference or a named object.
/*
    * This i sfine. The temp is destroyed when its refrence or named object goes out of scopre.
    * Temp object cannot be bound to a non-const value reference.
*/
void g(const string &, const string &);

void h(string &s1, string &s2)
{
    const string &s = s1 + s2;
    string ss = s1 + s2;

    g(s, ss); // we can use s and ss here.
};

int main()
{
}