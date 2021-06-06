#include <iostream>
using namespace std;

/*
    * if you want a garantee that a value is computed at compile time,
        declare it constexpr and make sure that all functions used in its evaluation
        are constexpr.

    * In general, a function cannot be evaluated at compile time and therefore 
        cannot be called in a constant expression.

    * By specifying a function constexpr, we indicate that we want it to be useable
        in constant expressions if given constant expression as arguments.
*/

constexpr int fac(int n)
{
    return (n > 1) ? n * fac(n - 1) : 1;
};

const f(int n)
{
    int f5 = fac(5); // may be evalutated at compile time
    int fn = fac(n); // evaluated at run time(n is a variable)

    constexpr int f6 = fac(6);  // must be evaluated at compile time
    constexpr int fnn = fac(n); // error: cant guarantee compile-time evaluation(n is a variable)

    char a[fac(4)];  //  OK: array bounds must be constants and fac() is constexpr
    char a2[fac(n)]; // error : array bounds must be constants and n is a variable
};

/*
    * To be evaluated at compile time, a function must consist of a single return-statement.
        NO LOOPS AND NO LOCAL VARIABLES!! are allowed.
        constexpr func may not have side effects, meaning it is a pure function:
*/
int glob;
constexpr void bad1(int a) // error: constexpr function cannot be void
{
    glob = a; // error: side effect in constexpr function
}

constexpr int bad2(int a)
{
    if (a >= 0)
        return a;
    else
        return -a; // error : loop in constexpr function
}

constexpr int bad3(int a)
{
    sum = 0; // error: local vriable in constexpr func
    for (int i = 0; i < a; += 1)
        sum += fac(i); // error : loop in constexpr function
}
/*
     However, you’ll find the debugging gets unnecessarily difficult and compile 
     times longer than you would like unless you restrict the use of constexpr functions
      to the relatively simple tasks for which they are intended.
*/

int main()
{
    //const expression
    constexpr int f9 = fac(9); // must be evaluted at compile time
};