#include <iostream>
using namespace std;
/*
    * A name defined in a function is commonly reffered to as a local name/
    *   A local variable or constant is initialized when a thread of execution 
    *   reaches its definition.
    *   UNLESS DECLARED STATIC, EACH invocation of the fucntion has its own copy of the variable.
    * 
    *   if a local variable is decalred STATIC, a single, statically allocated object will be 
    *   used to represent that variable in all calls of the function .
    * 
    *   It will be initialzlied only the first time a thread of execution reaches its definition. 
*/

void f(int a)
{
    while (a--)
    {
        static int n = 0; // initialized once
        int x = 0;        // initialized 'a' times in each call of f()

        cout << "n ==" << n++ << ", x==" << x++ << '\n';
    }
}

int fn(int n)
{
    static int n1 = n;             //OK
    static int n2 = fn(n - 1) + 1; // undefined
    return n;
}
int main()
{
    f(3);

    /*
        outputs:
        n == 0, x==0
        x == 1, x==0
        n == 2, x==0

        A static local variable allows the function to preserve information between calls without 
        introducting a global variable that might be accessed and corrupted by other functions.
    */
}
