#include <iostream>
using namespace std;
/*
    Function that take two arguments, an iteger array a and its length n.

    it determines whether the sum of array values is even, and if so it returns the value true.

    otherwise false. Thus a return type of bool.
*/

struct Passenger
{
    string name;      //passenger name
    bool isFreqFlyer; // passenger frequent flyer program?
    string freqFlyNo; // the passenger freq. flyer number
};

//first declearation
bool evenSum(int a[], int n); // function declaration

// second declearation
bool evenSum(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) // sum the array elements
        sum += a[i];
    return (sum % 2) == 0; // returns true if sum is even.
}

void f(int value, int &ref) // one value and one reference
{
    value++;               // No effect on the actual argument
    ref++;                 // modifies the actual argument
    cout << value << endl; // outputs 2
    cout << ref << endl;   // outputs 6
}

void someFunc(const Passenger &pass)
{
    pass.name = "new name"; // ILLEGAL! pass is declared const
}

//overloading
void print(int x)
{
    cout << x; // print int
}

void print(const Passenger &pass)
{
    // print Passenger members
    cout << pass.name << " " << pass.isFreqFlyer;
}
int main()
{

    int list[] = {4, 2, 7, 8, 5, 1};
    bool result = evenSum(list, 6); //invoke the function

    if (result)
        cout << "the sum is even\n";
    else
        cout << " the sum is odd\n";
    return EXIT_SUCCESS;

    int cat = 1;
    int dog = 5;
    f(cat, dog);         // pass cat by value, dog by ref
    cout << cat << endl; // outputs 1;
    cout << dog << endl; // outputs 5

    return EXIT_SUCCESS;
}