
#include <iostream>
using namespace std;

/*
    Consider copying ten elements from one array to another:
*/
void copy_fct()
{

    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10]; // array holding 10 elements, to become a copy of v1
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // for loop
    for (auto i = 0; i != 10; ++i) // copy elements
        v2[i] = v1[i];
    // cout << "v2: " << v2 << "\n";

    // RANGE-FOR-STATEMENT: for loops that TRAVERSE A SEQUENCE // plae a copy of v in x
    for (auto x : v) // for each x in v
        cout << x << '\n';

    for (auto x : {10, 21, 32, 43, 54, 65})
        cout << x << '\n';

    // Instead of COPYING, by Reference
    for (auto &x : v)
        ++x;

    /*
        unrary suffix & means "reference to". Similar to a pointer, except you don't need to use * to access the value
        reffered to by the reference.
        A reference cannot be made to refer to a different object after initialization.
    */

    // References are paticularly useful for specifying function arguments.
    void sort(vector<double> & v); // sort v

    // we ensure that for a call sort(my_vec), we do not copy my_vec and that it really is my_vec
    // that is sorted and not a copy of it
}

// when you dont want to modify an argument, but still don't want the cost of copying, we use a const reference.
double sum(const vector<double> &)
{
    // functions taking const references ary very common.
}
int main()
{
    //inline function
    inline int min(int x, int y) { return (x < y ? x : y); }
    copy_fct();
}