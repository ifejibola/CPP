using namespace std;
#include <iostream>
#include <vector>
//LIST & UNQAULIFIED LISTS
/*
    * In addition to their use for initializing named variables.
    * {}=list can be used as expresssions in many but not all  
*/

struct S
{
    int a, b;
};

struct SS
{
    double a, b;
};

void f(S); // f() takes an S

void g(S);
void g(SS); // g() is overloaded

void h()
{
    f({1, 2}); // OK: call f(S{1,2})

    // g({1, 2}); // error: ambiguos

    g(S{1, 2});  // Ok : call g(S)
    g(SS{1, 3}); // OK : call g(SS)
};
/*
    * As in their use for initializing named variables, lists can have zero, one, or more elements.
    * A {} list is used to contruct and object of some type, so the number of elements and their types
    * must be what is required to contruct an object of that type.
*/

void list()
{
    vector<double> v = {1, 2, 3.14}; // std lib vector has an initializer-list contructor.
};

// Unqualified Lists
/*
    * A unqualified list is used where an expected type if unambiguously known.
    * It can be used as expression only as:
        *   A function argument
        *   A reutrn value
        *   The right-hand operand of an assignment operator(=, +=, *= etc).
        *   A subscript 
*/

int f(double d, Matrix &m)
{
    int v{7};           // initializer (direct initialization)
    int v2 = {7};       // initializer (copy initialization)
    int v3 = m[{2, 3}]; // assume m take value pairs as subscripts

    v = {8};      // right-hand operand of assignment
    v += {88};    // right-hand operand of assignment
    {v} = 9;      // error: not left-hand operand of assignment
    v = 7 + {10}; // error: not an operand of a non-assigment operator
    f({10.0});    // function argument
    return {11};  //return value
};

int high_value(initializer_list<int> val)
{
    //     int high = numeric_traits<int>lowest();

    /*
    *   A {}-list is the simplest way of dealing with homogeneous lists of varying lengths.
    *   However, beware that zero elemtns can be a special case. If so,
    *   that case should be handled by a defualt constructor.
*/
    auto x0 = {};        // error(no element type)
    auto x1 = {1};       // initializer_list<int>
    auto x2 = {1, 2};    // initializer_list<int>
    auto x3 = {1, 2, 3}; // initializer_list <int>
    auto x4 = {1, 2.0};  // error: nonhomogeneous list
}