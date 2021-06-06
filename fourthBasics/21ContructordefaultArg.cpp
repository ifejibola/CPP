#include <iostream>
using namespace std;

class complex
{
    double re, im;

public:
    complex(double r, double i) : re{r}, im{i} {}; // construct complex from two scalars
    complex(double r) : re{r}, im{0} {}            // construct complex from one scalar

    complex() : re{0}, im{0} {}; // default complex : {0,0};

    /*
        * constructors do more work and the repetitiveness is common.
        * We could deal with repetitiveness by:
    */
    complex(double r, double i) : re{r}, im{i} {} // contruct complex from two scalars
    complex(double r) : complex{2, 0} {}          // contruct copmlex from one scalar
    complex() : complex{0, 0} {}                  //default complex:{0,0};

    /*
        * say we wanted to add some debugging, tracing, or statistics-gathering code to complex;
        * we now have a single palce to do so.
        *   THIS CAN BE  ABBREVIATED FUTHER:
   */

    complex(double r = {}, double i = {}) : re{r}, im{i} {} // contruct complex from two scalars

    /*
        * This makes it clear that if a user supplies fewer than the two arguments needed, 
            the default is used. 
        * The intent of having a single contructor plus some shorthand 
            version notation is now explict.
    */
};

/*
    * Default arguments that can change value are most often best avoided because they 
        introduce suble context dependencies

    *  Default arguments may be provided for trailing argumetns only. E.G:
*/

int f(int, int = 0, char * = nullptr); //OK
int g(int = 0, int = 0, char *);       // error
int h(int = 0, int, char *= nullptr);  //error
