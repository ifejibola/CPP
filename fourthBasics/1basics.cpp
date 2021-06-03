#include <iostream>
using namespace std;

int anotherMain()
{
    std::cout << "Hellow, World!\n";
}

// square a double precision floating-point number
double square(double x)
{
    return x * x;
}

// print sqaure double precision floating-poitn number
void print_square(double x)
{
    cout << "the square of " << x << "is " << square(x) << "\n";
}

/*
 when defining a variable, you don't actually need to state its 
 type explicitly when it can be deduced from the initializer:
 */
auto b = true; // a bool
auto ch = 'x'; // a char
auto i = 123;  // an int
auto d = 1.2;  // a double

/*
    CONSTANTS
    - For a function to be usable in a constant expression, that is, in an expression
    that will be evaluated by the compiler, it must be defined constexpr 
*/
constexpr double squaree(double x)
{
    return x * x;
}

const int dmv = 17;                         // named constant
int var = 17;                               // var is not a constant
constexpr double max1 = 1.4 * squaree(dmv); // will only work if squaree is a constant expression
                                            // constexpr double max2 = 1.4 * squaree(var); //error: var is not a const

/*
    A simple function that prompts the user and returns a Boolean indicating the response:

    << (put to ), the >> operator("get from") is used for input;
*/
bool accept()
{
    cout << "Do you want to proceed (y or n)?\n"; //write question

    char answer = 0;
    cin >> answer; //read answer

    if (answer == 'y')
        return true;
    return false;
}

/*
    A switch statement test a value against a aset of 
*/
bool accept2()
{
    cout << "Do you want to proceed (y or n)?\n"; // write question

    char answer = 0;
    cin >> answer; // read answer

    switch (answer)
    {
    case 'y':
        return true;
    case 'n':
        return false;
    default:
        cout << "I'll take that for a no.\n";
        return false;
    }
}

int main()
{
    accept();
    accept2();
    print_square(1.234); // print square
}
