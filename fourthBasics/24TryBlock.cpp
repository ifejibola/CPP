#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// The body of a function can be a try-block

void f()
{
    try
    {
    }
    catch (...)
    {
    }
};

/*
    * Try block allows us to deal with exceptions thrown by base-or-member initializers in 
    constructors.

    * By defualt, if an exception is thrown in a base-or-member initializer, the exception is 
    passed on to whatever invoked the constructor for the member's class.

    * However, the constructor itself can catch such exceptions by enclosing the complete function body
    - Including the member intializer list in try-block.
*/

class X
{
    vector<int> vi;
    vector<string> vs;

public:
    X(int, int);
};

X::X(int sz1, int sz2)
try : vi(sz1), // construct vi with sz1 ints
    vs(sz2)    // construct bs with sz2 strings
{
    //
}
catch (std::exception &err)
{
    // exception thrown for vi and vs are caught here
};

int main(){};