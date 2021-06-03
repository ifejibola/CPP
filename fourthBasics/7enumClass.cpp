#include <iostream>
using namespace std;

/*
    * An enumeration is a type that can hold a set of integer values specified by the user


    There are two kinds of enumerations:
    [1] enum classes, for which the enumerator names (e.g., red) are local to the enum and their
    values do not implicitly convert to other types
    [2] ‘‘Plain enums,’’ for which the enumerator names are in the same scope as the enum and
    their values implicitly convert to integers


    * An enum class is a scoped and strongly typed enumeration.

    Note that the enumerators present in both enums do not clash because 
    each is in the scope of its own enum class.
*/
enum class Traffic_light
{
    //enumerators
    red,
    yellow,
    green
};
enum class Warning // enum with enumerators
{
    //enumerators
    green,
    yellow,
    orange,
    red
}; // fire alert levels

void f(Traffic_light x)
{
    if (x == 9)
    {  /**/
    }; // error: 9 is not a Traffic_light

    if (x == red)
    {  /**/
    }; // error: no red in scope

    if (x == Warning::red)
    {  /**/
    }; // error: x is not a Warning

    if (x == Traffic_light::red)
    { /**/
    } // OK
};

/*
    * Anenumeration is represented by some integer type and each enumerator by some integer value
    * We call the type used to represent an enumeration its underlying type.
    * The udnerlying type must be one of the signed or unsigned integer types; the default is int.
    *   We could be explicit about that:
*/
enum class Warning : int
{
    green,
    yellow,
    orange,
    red
}; // sizeof(Warning)==sizeof(int)

enum class Warning : char
{
    green,
    yellow,
    orange,
    red
}; // sizeof(Warning)==1
int main()
{
    Warning a1 = 7;               // error : no int-> Warning conversion
    int a2 = green;               // Error: green not in scope
    int a3 = Warning::green;      // Error: no Warning -> int conversion
    Warning a4 = Warning ::green; // OK
}