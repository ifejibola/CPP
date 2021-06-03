#include <iostream>

using namespace std;

/*
    * An ARRAY is an aggregate of elements of the same type.
    In its simplest form, a struct is an aggregate of elemtns
    of arbitrary types. FOR EXAMPLE 

    * This defines a type called Address, consisting of items needed 
    to send mail to someone within USA.

    Individual members can be accessed using the .(dot) operator.


*/
struct Address
{
    const char *name;   // jim
    int number;         // 61
    const char *street; // southt st
    const char *town;   // New Providence
    char state[2];      // 'N' 'J'
    const char *zip;    //07974
};

void f()
{
    Address jd;
    jd.name = "jim";
    jd.number = 2;

    // Variables of struct types can be initialized using {}
    Address ifes = {
        "Ife Ajibola",
        47,
        "Redondo Dr",
        "Thornhill",
        {'O', 'N'},
        "L4J 7S7"};

    // cout << ifes.toString();
};

/*
    * Structs are often accessed through pointers using the ->
        (struct pointer dereference) operator.
*/
void print_addr(Address *p)
{
    cout << p->name << '\n'
         << p->number << ' ' << p->street << '\n'
         << p->town << '\n'
         << p->state[0] << p->state[1] << ' ' << p->zip << '\n';
};

/*
    * ALternatively, a struct can be passed by reference and accessed
    using the . (struct member access ) operator.
*/
void print_addr2(const Address &r)
{
    cout << r.name << '\n'
         << r.number << '' << r.street << '\n'
         << r.town << '\n'
         << r.state[0] << r.state[1] << '' << r.zip << '\n';
};

// return initial value but set new value
// Address current;
// Address set_current(Address next)
// {
//     address prev = current;
//     current = next;
//     return prev;
// }

/*
    * You can minimize wasted space by simply ordering member by size(largest member first).
*/
struct Readout
{
    int value;
    char hour;
    char seq;
};
// Struct name delcaration: members/list to be defined later
struct List;
struct Link
{
    Link *pre;
    Link *suc;

    List *member_of;
    int data;
};

struct List
{
    Link *head;
} struct List
{
    Link *head;
};

int main()
{
    cout << "main" << '\n';
}