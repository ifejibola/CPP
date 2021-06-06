#include <iostream>
using namespace std;

/*
    * ++ operator is used to express increment directly, 
        rather than using combination of an additon and an assignment

    * ++k means k+=1, which means k=k+1;

    * The value of ++ x is the new (that is, incremented) value of x.
        E.G : y = ++ x  means y = (x = x+1). 

    * The value of x++ is : the old value of x.

    very useful in loops
*/

void cpy(char *p, const char *q)
{
    while (*p++ = *q++)
        ;
}

void cpy2()
{

    //1
    // Consider a traditional way of copying an array of characters:
    int length = strlen(q); // q is assumed to be an array
    for (int i = 0; i <= length; i++)
        p[i] = q[i]; // copy q into p
    /*
  ^^  this is wateful. Length of a zero-terminated string is found by reading the string looking for 
  the terminating zero.
        Meaning, we read the string twice: once to find its length and once to copy it. 

    TRY this 
*/
    //2
    int i;
    for (i = 0; q[i] != 0; i++)
        p[i] = q[i];

    p[i] = 0; //terminating zero

    //3 Or
    // The variable
    while (*q != 0)
    {
        *p = *q;
        p++; //point to next char
        q++; // point to next char
    };
    *p = 0; // terminating zero
}
