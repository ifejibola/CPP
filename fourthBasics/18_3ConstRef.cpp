#include <iostream>
using namespace std;
// constexpr and References

/*
    * A constexpr function cannot have side-effects, so writing to nonlocal object is not possible

    * HOWEVER ! a constexpr function can refer to nonlocal objects as long as it does not write to them.
*/

constexpr int ftbl[]{1, 2, 3, 4, 5, 6, 7};

constexpr int fib(int n)
{
    return (n < sizeof(ftbl) / sizeof(*ftbl)) ? ftbl[n] : fib(n);
};

/*
    * A constexpr function can take reference arguments.

    * of course, it cannot write thorugh such references, but const reference parameters
        are useful.
*/

// return ref or pointer
constexpr const int addr(const int &r) { return &r; }; //ok
