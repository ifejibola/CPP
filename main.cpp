#include <iostream> // instructs the complier to include the declaration of the standard stream I/O facilities as found in iostream.

int main()
{
    std::cout << "Hello world\n"; // iostream allows us to use std::cout
}

using namespace std; // make names from std visible without std::

double square(double x) // square a double precision floating-point number
{
    return x * x;
}

void print_square(double x) // return type void indicates that a function does not return a value.
{
    cout << "the seqare of" << x << square(x) << "\n";
}

int amain() //#main(you get the point)
{
    std::cout << "Hello world\n"; // iostream allows us to use std::cout
    print_square(1.234);          // print: square of 1.234 is 1.52276
}