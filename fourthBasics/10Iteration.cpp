#include <iostream>
#include <vector>
using namespace std;

/*
    for (int x: v) can be read as "for each element x in the range v"
        or just " for each x in v " 
    
    * The elements of v are visited in order from the first to the last.
*/
int sum(vector<int> &v)
{

    //expression
    int s = 0;
    for (int x : v)
        s += x;
    return s;
};

/*
    The expression after the colon must denote a sequence(a range); that is,
    yield a value for which we can call v.begin() and v.end()
    or
    begin(v) and end(v to obtain an iterators)

    * The controlled variable, x in the example(refering to the sum() above), that referes to the current element 
    is s
*/
int sum2(vector<int> &v)
{
    int s = 0;
    for (auto p = begin(v); p != end(v); ++p)
        s += *p;
    return s;
}

/*
    * If you need to modify an element in a range-for lopp, the element variable should be a reference.

    WE can increment each element for a vector like this:
*/

void incr(vector<int> &v)
{
    for (int &x : v)
        ++x;
};

// References are also appropriate for elements that might be large, so that coying them to the element
// value could be costly.

/*
    * MORE FOR STATEMNET 
        General for-statement allowing greter control of the iteration.
            The loop variable, the termination condition, and the expression that updates the loop
            variable are explicitly set upfront 
*/

void f(int v[], int max)
{
    for (int i = 0; i != max; i++)
        v[i] = i * i;

    // EQUIVALENT TO

    int g = 0;       //introduce loop variable
    while (g != max) //test termination condition
    {
        v[g] = g * g; //execute the loop body
        ++g;          //increment loop variable
    }

    //its not always obvious what is the right type of variable in the initializer part of a for-statement.
    // so auto often comes in handy :

    // for (auto initialierVariable = begin(c); v != end(c); ++initialierVariable)//example only!
    // {
    // }
};

/*
    * Reading and testing for termination and combined in cin>>s, so we don't need an explicit
    loop variable.

    On the other hand, the use of for, rather than while, allows us to limit the scope of the 
    "current element", s, to the loop itself(the for statement )
*/
void elegant()
{
    for (string s; cin >> s;)
    {
        // v.push_back(s);
    }
};