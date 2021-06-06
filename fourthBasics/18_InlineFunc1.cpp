#include <iostream>
using namespace std;

// A dunction can be defined to be inline
inline int fac(int n)
{
    return (n < 2) ? 1 : n * fac(n - 1);
};

/*
    *   The inline specifier is a hint to the compiler that it should attempt to generate
        code for a call of fac() inline.

        Rather than laying down the code for the function once and then calling though the
        usual func call mechanism.
*/
