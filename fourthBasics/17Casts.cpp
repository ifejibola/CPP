#include <iostream>
#include <vector>
using namespace std;

/*
    * Explict type conversion, often called casting, is occasionally essential.
    * However it is overused and a major source of errors.
    * 
    * 
    * Needed When : used for explicit type conversion is dealing with "raw memory",
    *   that is, memory that holds or will hold objects of a type not known to the compiler.
*/
void *my_allocator(size_t);

void f()
{
    int *p = static_cast<int *>(my_allocator(100)); // new allocation used as ints
};

/*
    * static_cast : converts between related types such as one pointer type to another in the same
    class hierachy, an integral type to an enumeration, or a floating-point type to an integral type.

    * reinterpret_cast : handles conversions between unrelated types such as an integer to a 
        pointer or a pointer to an unrealted pointer type.

    * const_cast : converst between types that differ only in const and volatile qualifiers

    * dynamic_cast : does run-time checked conversion of pointers and references into a class
        hierarchy.
*/

void cast()
{
    char x = 'a';
    int *p1 = &x;                          // error: no implicit char*  to int* conversion
    int *p2 = static_cast<int *>(&x);      // error: no implicit char* to int* conversion
    int *p2 = reinterpret_cast<int *>(&x); // OK

    struct B
    {
    };
    struct D : B
    {
        /* data */
    };

    B *pb = new D;                // Ok: implicit conversion from D* to B*
    D *pd = pb;                   // error: no implicit conversion from B* to D*
    D *pd = static_cast<D *>(pb); // OK
};