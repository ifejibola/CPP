#include <iostream>
#include <vector>
#include <system_error>
#include <exception>
using namespace std;

/*
    A declaration is a statement. Unless a variable is declared static, its initizalizer is 
    executed whenever the thread of control passes through the declaration.
*/

void f(vector<string> &v, int i, const char *p)
{
    if (p == nullptr)
        return;
    if (i < 0 || v.size() <= i)
        // error("bad index");
        cout << "bad index";
    string s = v[i];
    if (s == p)
    {
    }
}

/*
    * The ability to place declarations after executable code is essential for many constants and
    for single-assignment styles of programming where a value of an object is not changed after
    initialization.

    * For user-defined types, postponing the definition of a variable until a suitable 
    initializer is available can also lead to better performance.
*/
void use()
{
    // empty initializaiton followed by an assignment..
    string s1;                                //variable
    s1 = "The best is the enemy of the good"; // this is a declaration/definition of the variable/initializer
};

// initialization with desired value:
string s2{"Voltaire"};

void input()
{
    int buf[10];
    int count = 0;
    for (int i; cin >> i;)
    {
        if (i < 0)
            cout << "hello";
        if (count == 10)
            cout << "buffer overflow";
        buf[count++] = i;
    };
};

/*
    Note that a plain enum can be implicitly converted to an integer and then to a bool,
    * whereas an enum class cannot 
*/
enum E1
{
    a,
    b
};
enum class E2
{
    a,
    b
};

void f(E1 x, E2 y)
{
    if (x) // ok
    {      //
    };
    // if (y) // error: no conversion to bool
    // {
    //     //
    // };
    if (y == E2::a) //ok
    {
        // SAFE
    }
};
