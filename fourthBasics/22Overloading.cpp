#include <iostream>
using namespace std;

// Overloaded functions

void print(int);          // print an int
void print(const char *); // print a c-style string

void print(double);
void print(long);

void f()
{
    print(1L);  // print(long)
    print(1.0); /// print(double)
    print(1);   // error: ambiguous: print(long(1)) or print(double(1))?
}
