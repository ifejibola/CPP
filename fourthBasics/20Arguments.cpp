#include <iostream>
#include <cstdarg>
using namespace std;

/*
    * Each formal argument is initialized by its coresponding ACTUAL argument.

    * The semantics of argument passing are identical to the semantics of initialization.

    * UNLESS A FORMAL ARGUMENT PARAMETER IS A REFERENCE, A COPY of the ACTUAL argument 
    is passed to the function.
    
     E.G:
*/

int *find(int *first, int *last, int v) // find x in [first: last]
{
    while (first != last && *first != v)
        ++first;
    return first;
}

void g(int *p, int *q)
{
    int *pp = find(p, q, 'x');
}

//REFERENCE ARGS
void f(int val, int &ref)
{
    ++val;
    ++ref;
}
/*
    * When f() is called, ++val increments a local copy of the first actual argument, whereas 
        ++ref increments the second actual argument
*/

void h()
{
    int i = 1; //copy passed
    int j = 1; // takes actual value
    f(i, j);
};

void restrictYourSelfTOViewOnly(const Large &arg)
{
    // the value of arg cannot(const) be changed, viewed maybe?
    // (except by using explicit type conversion)
}

// ARRAY
/*
    * If an array is used as a function argument, a pointer to its inital element is passed.

*/

int strglen(const char *);

void l()
{
    char v[] = "Annemarie";
    int i = strglen(v);
    int j = strlen("Nicholas");
    /*
        * An argument of type T[] will be converted to a T* when passed as an argument.
    */
}

/*

      * Arrays differ form other types in that an array is not passed by value.

        * Instead, a pointer is passed (by value).

            * A parameter of array type is equivalent to a paramenter of pointer type.

*/
void odd(int *p);
void odd(int a[]);
void odd(int buf[1020]);
//These 3 delcarations are equivalent and delcare the same func.

/*
    The size of an array is not available to the called function.

    * This is a mahor source of errors.

    * Prevented by second argument specifying the size can be passed :
*/

void compute1(int *vec_ptr, int vec_size); //one way
                                           // It is usually perfereable to pass a reference to some container, such as a vector, array, or map.

/*
    * If you really want to pass an array, rather than a container or a pointer to the first
        element of an array, you can delcare a parameter of type reference to array.
*/

void ff(int (&r)[4]);

void g()
{
    int a1[] = {1, 2, 3, 4};
    int a2[] = {1, 2};

    ff(a1); //ok
    ff(a2); // error: wrong number of elements
}

/*
    NOTE: The number of elements is part of reference to array type.

        * That makes it less flexible than pointers and containers(such as vector).

        * The MAIN use of references to arrays is in templates where the number of elements
        is then deduced.
*/

/*
    UNSPECIFIED NUMBER OF ARGUMENTS

    * For some Func, it is not possible to specify the number and tyep of all arguments 
        expected in a call.
    * TO implement such interfaces we have these options :

    * Variadic template : this allows us to handle an arbitrary number of arbitrary
        types in a type-safe manner by writting.

    * Use an INITIALIZER_LIST as the argument type : Allows handle of arbitrary number of arguments
        of a single type in a type-safe manner.

        * A well designed promgram needs at most a few functions where argument types are not
            completely specified.
        * Overloaded functions, functions using default arguments, functions taking 
            initializer_list arguments, and variadic templates can be used to take care
            of tpe checking in most cases when one would otherwise consider leaving 
            arguments types unspecfied.

        The only time when you need to use the ELLIPSIS : when both number of arguments and types
        of arguments vary and a variadic template solution is deemed undesireable.(used more in old c++)
*/

/*
    Error function : Takes one intger argument indicating the severity of the error 
                    followed by an arubitrary number of strings.

                The Idea is to compose the error message by passing each word as a seprate Cstytle
                string argument. THE list of string arguments should be terminated by the null
                pointer:
*/

extern void error(int...);
extern char *itoa(int, char[]); // int to alpha

void error(int severity...) // "severity" followed by a zero-terminated list of char's
{
    //macro
    va_list ap;
    va_start(ap, severity); //arg startup

    for (;;)
    {
        char *p = va_arg(ap, char *);
        if (p == nullptr)
            break;
        cerr << p << ' ';
    }

    va_end(ap); // arg cleanup

    cerr << '\n';
    if (severity)
        exit(severity);
}
int main(int argc, char *argv[])
{

    // argv[0] : conventionally is the name of the program

    switch (argc)
    {
    case 1:
        error(0, argv[0], argv[1], nullptr);
        break;
    case 2:
        error(0, argv[0], argv[1], nullptr);
        break;

    default:
        char buffer[8];
        error(1, argv[0], "with", itoa(argc - 1, buffer), "arguments", nullptr);
    }
}