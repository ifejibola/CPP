/*
    POINTERS, ARRAYS, AND LOOPS


    POINTER
        *   A pointer variable can hold the address of an object of the appropriate type
        *   In an expression, prefix unary ∗ means ‘‘contents of’’ and prefix unary & means
        *  ‘‘address of.’’
        * 
        * We try to ensure that a pointer always points to an object, so that dereferencing it is valid.
        * 
        * When we don’t have an object to point to or if we need to represent the notion of ‘‘no object available’’ 
        * (e.g., for an end of a list), we give the pointer the value nullptr (‘‘the null pointer’’).
        * There is only one nullptr shared by all pointer types:
*/
#include <iostream>
using namespace std;

// ARRAY
//  An array of type char can be declared like this:
char v[6]; // array of 6 char

//COPY 10 ELEMENTS FROM ONE ARRAY TO ANOTHER
void copy_fct()
{
    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10]; // to become copy

    for (auto i = 0; i != 10; ++i) // copy elements
        v2[i] = v1[i];
}

// for loops that traverse a sequence in the simplest way:
void print()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto x : v) // for each x in v
        cout << x << '\n';

    for (auto x : {10, 21, 32, 43, 54, 65})
        cout << x << '\n';
}
/*
    If we didn’t want to copy the values from v into the variable x, but rather 
    just have x refer to an element, we could write:
*/
void increment()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // &x'refference to' each element of v
    for (auto &x : v)
        ++x;
}
// POINTERS
char b = 'a';
char *p; // pointer to character

char *a = &v[3]; // a points to v's fourth elements address
char x = *p;     //safe  BUT WILL CRASH IN RUN TIME AS ERROR: SEGMENTATION FAULT, accessing memory that " does not belong to you"
double *pd = nullptr;

char isPointing(char *a)
{
    if (a == nullptr)
        return 't';

    if (a != nullptr)
        return 'f';
}

int main()
{
    cout << "hello\n";
    auto data = isPointing(a);
    cout << data;
}

// DONTS POINTERS

// p = &v[2];      // cannot change pointer value like this
