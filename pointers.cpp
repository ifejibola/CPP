#include <iostream>
using namespace std;
/*
    For a type T, T* is the type "pointer to T". That is, a variable of Type T* can hold the
    address of an object of type T.
*/

char c = 'a';
char *p = &c; // p holds the address to c; & is the address of operator

// FUndamental operation on a pointer is DEREFERENCING
// referring to the object(c:'a') pointed to by the pointer(*p)
// const char p[] = {'a', 'b', 'c', 0};

int count_x(char *p, char x)
{
    /* often wise to hcekc that a poitner argument that is supposed to point
 to something, acually points to something
*/

    // count the number of occurrences of x in p[]

    if (p == nullptr)
        return 0;
    int count = 0;
    for (; p != nullptr; ++p)
        // Note that we can move a pointer to pint to the next element of an array using ++
        // and that we can leave out the initializaer in a for-statement if we don't need it.
        if (*p == x)
            ++count;
    return count;
}
int count_y(char *p, char x)
{

    // count the number of occurrences of x in p[]
    // p is assumed to point to a zero terminated array of char (or to nothing)

    int count = 0;
    while (p)
    {
        if (*p == x)
            ++p;
    }
    return count;
}

int main()
{
    char ch = 'Q';
    char *p = &ch;      // p now holds referrence/address of ch
    cout << *p;         // outputs the char 'Q'
    ch = 'Z';           // ch now holds Z
    cout << *p;         // outpurs the char Z
    *p = 'X';           // ch now holds'X'
    cout << ch << '\n'; // outputs the char X

    //array
    char c[] = {'c', 'a', 't'};
    char *pointr = c; // point to c[0]

    cout << *pointr;
}