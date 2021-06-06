#include <iostream>
using namespace std;

/*
    * It is often useful to create an object that exist independtly of the scope it was created.

    * E.G : It is common to create objects that can be used after returning from the function they were created.

    The operator : new : creates such objects

    The operator : delete : used to destroy objects

    Objects allocated by new are said to be on the free store(heap, dynamic memory)


    * If a type has a defualt contstructor, we can leave out the initialzier, but built-in
    types are by default uninitialized.
*/

auto pc = new complex<double>; // the complex is initialized to {0,0};
auto pi = new int;             // the int is uninitialized.

/*
    * This can be confusing. 

    * Use default initiazation, {}

    E.g
*/

auto pc = new complex<double>{}; // the complex is intialized to {0,0}
auto pi = new int;               // the int is uninitialized