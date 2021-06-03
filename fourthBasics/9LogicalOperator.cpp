#include <iostream>
using namespace std;
/*
    * LOGICAL OPERATORS 
*/
int max(int a, int b)
{
    return (a > b) ? a : b; // return the larger of a and b
};

// SWITCH

void f(int i, int val)
{
    switch (i)
    {
    case 1:
        /* code */
        break;

    default:
        break;
    }

    // A switch-statement can laternatively be written as a set of if-statement.

    switch (val)
    {
    case 1:
        /* code */
        break;

    default:
        break;
    }

    //This switch ^ could be expressed as:
    if (val == 1)
        cout << "1";
    else if (val == 2)
        cout << "2";
    else
        cout << "neither 1 or 2";
}
