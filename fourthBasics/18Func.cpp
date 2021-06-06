#include <iostream>
using namespace std;

/*
    * A function cannot be called unless it has been declared. 

    * A function delcaration : gives the name of the function, the type of the value returned(if any)
        and the number and types of the arguments that must be supplied in a call.


    PARTS OF A FUNCTION DECLARATION :

        *   The name of the function; required.
        *   The argument list, which may be empty(); required
        *   The return type, which may be void and which may be prefic or suffix(using auto); requried
        *   inline : indicating a desire to have function.
        * 
        *   constexpr : indicating that it should be possible to evalute the function at compile time
        *       if fiven constant expressions as arguments.
        * 
        *   noexcept: indicating that the function may not throw an exception
        * 
        *   A loinkage specification, E.G, static.
        * 
        * [[noreturn]], indicating that the function will nto reutrn using the normal call/return mechanism
        * 
        *  IN ADDITION : a member function may be specified as:
        *       virual : indicating that it can be overriden in a derived class.
        *       override : indicating that it must be overriding a virtual function from a vase class
        *       final : indicating that it cannot be overriden in a derived class
        *       static : indicating that it is not associated with a perticular object
        *       const : indicating that it may not modify its object.
*/

// // Function Declarations/Definitions
/*
    * every function that is called must be defined somewhere. A function definition is a function
    decalration in which the body of the function is presented.
*/

void swap(int *, int *); // A DECLARATION

void swap(int *p, int *q) // A DEFINITION
{
    int t = *p;
    *p = *q;
    *q = t;
};

/*
    * The definition and all declarations for a function must specify the same type.

    * const is ignroed at the highest lvl of an argument type.
    E.G
*/

void f(int);       // type is void (int)
void f(const int); // type is void(int)

//
void f(int x){/* we can modify x here*/};
void f(const int x){/* we cannot modify x here! */};

/*
    * Every function declaration contains a specificaiton of the functions return type.

    * A function DECLARATION can also be written using a syntax that places the return type after 
        the argument list.
*/

// TWO equivalent declarations :
string to_string(int a);         // prefix return type
auto to_string(int a) -> string; // suffix return type
// that is a prefix auto indicates the return type is places after the argument list.

// A VALUE CANNOT BE REUTRNED FROM A VOID FUNCTION
int f1() {}  ///error : no value returned
void f2() {} // OK

int f3() { return 1; }  //ok
void f4() { return 1; } // error: return value in void function

/*
    * Each time a function is called, a new copy of its arguments and local(automatic) variables
    is created. The store is reused after the function returns, so a pointer to a local 
    non-static variable should never be returned.

    * The contents of the location pointed to will change unpredictably:
*/
int *fp()
{
    int local = 1;

    return &local; // bad!!
};

int &fr()
{
    int local = 1;

    return local; // bad!!!
};

// a void function can return another void function

void g(int *p);

void h(int *p)
{
    return g(p); // ok: equivalent to
}