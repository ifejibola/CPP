#include <iostream>
using namespace std;

/*
    * The code generated for a function body is placed in memory 

    * We can have a pointer to a function jsut as we can have a pointer to an obejct.

    * FOR SOME REASON related to machine architechture : 
        * A pointer to function does not allow the code to be modified.
        * There are only two things one can do to a function : call it and take its address.
        * The pointer obtained bytaking the address of a function can be used to call the func
*/

void error(string s){
    /*
        *
    */
};

void (*efct)(string); // pointer to function taking string argument and returning nothing

void f()
{
    efct = &error; // efct points to error
    efct("error"); // call error through efct
};

void (*f1)(string) = &error; // OK: saem as =error
void (*f2)(string) = error;  // OK: same as = &error

void g()
{
    f1("Vasa");         //OK: same as (*f1)("vasa")
    (*f1)("Mary Rose"); // OK: as f1("Mary Rose")
};

/*
    Poitners to functions have arguments types declared just like the funtions themselves.
*/

void (*pf)(string); //pointer to void (String)
void f8(string);    // void (String)
int f9(string);     // int (string)
void f3(int *);     //void (int*)

void ff()
{
    pf = &f8; //OK
    pf = &f9; // error: bad return type
    pf = &f3; // error: bad argument type

    pf("HERA"); //OK
    pf(1);      // error: bad argument type

    int i = pf("Zeus"); // error: valid assigned to int
};
