#include <iostream>
#include <vector>
using namespace std;

/*
    NOTE: it is recommended to avoid use of do-statements.
    A while statement executes its controlled statement util its condition becomes false.

    Tend to prefer while-statements over for-statements when there isnt an obvious loop 
    variable or where the update of a loop variable natuarally comes in the middle of the
    loop body.

    A for-statement is easily rewritten into an equivalent while-statement and vice versa
*/

bool isPresent = true;
void f()
{
    while (!isPresent)
    {
        //forever
    };
}

/*
    DO STATEMENT :
        * A do-statement is similar to a while-statement except that the condition comes after the body.
*/
void print_backwards(char a[], int i) // I must be positive
{
    cout << '{';
    do
    {
        cout << a[--i];
    } while (i);
    cout << '}';
};

/*
    * LOOP EXIT
    * If the condition of an iteration statement (a for-, while-, or do-statement) is omitted,
    *  the loop will not terminate unless the user explicitly exits it by a break, return
    * 
    *  goto, throw, or some less obvious way such as a call of exit()
*/

void loopExit(vector<string> &v, string terminator)
{
    char c;
    string s;
    while (cin >> c)
    {
        //
        if (c == '\n')
            break;
        //
    };
};

/*
    * CONTINUE skips the rest of the body of an iteration-statement.
*/

void find_prime(vector<string> &v)
{
    for (int i = 0; i != v.size(); ++i)
    {
        // if (!prime(v[i]))
        //     continue;
        // return v[i];
        // or

        // if (!prime(v[i]))
        // {
        //     return v[i];
        // }
    };
}

/*
    * GOTO

    You can use goto to jump both inot and out of blocks.
    * The only restriction is that you cannot jump past an initializer or into 
    an exception handler

    * One of the few sesible uses of goto in ordinary code is to break out from a nested loop or
    switch statement
*/

void do_something(int i, int j){
    // odo something to a two-dimensional matrix called mm

    //     for (i = 0; i != n; ++i)
    //         for (j = 0; j != m; ++j)
    //             if (nm[i][j] == a)
    //                 goto found;

    //     // not found
    //     // ...

    // found:
    // nm[i][j] == a
};

// Advice
// [1] Don’t declare a variable until you have a value to initialize it with;
// [2] Prefer a switch-statement to an if-statement when there is a choice;
// [3] Prefer a range-for-statement to a for-statement when there is a choice;
// [4] Prefer a for-statement to a while-statement when there is an obvious loop variable;
// [5] Prefer a while-statement to a for-statement when there is no obvious loop variable;
// [6] Avoid do-statements;
// [7] Avoidgoto;
// [8] Keep comments crisp;
// [9] Don’t say in comments what can be clearly stated in code;
// [10] State intent in comments;
// [11] Maintain a consistent indentation style;