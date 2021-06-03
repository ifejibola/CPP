#include <iostream>

using namespace std;

/*
    * A union is a struct in which all members are allocated at the same address so that the 
    union occupies only as muhc space as its largest member

    * Use of unions can be essential for compactness of data and through that for performance.
    (unions are considered overused feature; avoid them when you can)

    A union cannot have virtual functions.
    [2] A union cannot have members of reference type.
    [3] A union cannot have base classes.
    If a union has a member with a user-defined constructor, a copy operation, a move opera-
    tion, or a destructor, then that special function is deleted (§3.3.4, §17.6.4) for that union;
    that is, it cannot be used for an object of the union type.
    [5] At most one member of a union can have an in-class initializer (§17.4.4).
[     6] A union cannot be used as a base class. 
*/

enum Type
{
    str,
    num
};
// struct Entry
// {
//     char *name;
//     Type t;
//     char *s; //use s if t==str
//     int i;   // use i if t ==num
// };
// void f(Entry *p)
// {
//     if (p->t == str)
//         cout << p->s;
// };
union Value
{
    char *s;
    int i;
};

struct Entry
{
    char *name;
    Type t;
    Value v; // use v.s if t==str; use v.i if t==num
};

void f(Entry *p)
{
    if (p->t == str)
        cout << p->v.s;
}
