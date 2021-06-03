#include <iostream>
using namespace std;
/*
    * Classes provide a way to define new user-defined types, with associated functions and operators.

    *   By restrict- ing access to certain class members, it is possible to separate out 
        the properties that are essential to a class’s correct use from the details needed 
        for its implementation.

    * A class consists of members. 
        Members that are variables or CONSTANTS, are DATA MEMEBERS (also called member variables) 
        and MEMBERS that are functions are called MEMBER FUNCTIONS (also called methods)
    
    *   Data members may be of any type, and may even be classes themselves, or pointers or references
        to classes.

        
        #Counter implements a simple counter stored in the members variable count.

    * Observe that the class definition is separated into two parts by the keywords public and
        private. 
        
    *   The public section defines the class’s public interface.
            These are the entities that users of the class are allowed to access.

    * In contrast, the private section declares entities that cannot be accessed by users of the class.
    
*/

class Counter
{

public:
    Counter();              //initializaiton
    int getCount();         // get the current count
    void increaseBy(int x); // add x to the count
private:
    int count; // the counters value
};

/**
 * In order to make clear to the compiler that we are defining member functions of Counter
 *      (as opposed to member functions of some other class), we precede each function name with 
 *      the scoping specifier “Counter::”.
*/

Counter::Counter() //contructor
{
    count = 0;
}
int Counter::getCount() //get current count, referred to as a "getter" function
{
    return count;
}

void Counter::increaseBy(int x) // add x to the count
{
    count += x;
}

//USE CLASS
// WE DECLARE A NEW OBJECT OF TYPE COUNTER, called ctr
int main()
{
    Counter ctr;            // An instance of Counter
    cout << ctr.getCount(); // prints the inital value (0)
};