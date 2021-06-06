/*
 * constexpr : Evaluate at compile time
    * constexpr role is to enable and ensure compile-time evaluatiokn, 
 * const : Do not modify in this scope
 */

int x1 = 7;
constexpr int x2 = 7;

constexpr int x3 = x1; // error : initializer is not a const expression( declaration: initializer)

constexpr int x4 = x2; // OK

void f()
{
    constexpr int y3 = x1; // error : initializer is not a constant expression
    constexpr int y4 = x2; // OK
};

constexpr int isqrt_helper(int sq, int d, int a)
{
    return sq <= a ? isqrt_helper(sq + d, d + 2, a) : d;
};

constexpr int isqrt(int x)
{
    return isqrt_helper(1, 3, x) / 2 - 1;
};

constexpr int s1 = isqrt(9); // sq becomes 3