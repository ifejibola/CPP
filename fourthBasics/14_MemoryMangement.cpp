using namespace std;
#include <iostream>
#include <vector>

/*
    * The main problems with free store are :
        * Leaked obejct: Using new and then forgeting to delte the allocated object
        *   Leaked Objects are potentially a bad problem, they cause a program to run out of space.
        * 
        * Premature delteion : deleting an object that has some other pointer to and later 
        *   use that other pointer.
        *   Almost always nasty problem because the pointer to the deleted object  no longer pointers
        *   to a valid object( so reading it may give bad results) and may indeed point to memory 
        *   that has been reused for another object.
        *   so writing to it may corrupt an unrelated object.
        * 
        * Double deletion: An object is deleted twice, invoking its destructor(if any ) twice.
        * 
*/
void manage()
{

    int *p1 = new int{99};
    int *p2 = p1;             // POTENTIAL TROUBLE!!
    delete p1;                // now p2 doesn't point to a valid object
    p1 = nullptr;             // gives a false sense of safety
    char *p3 = new char{'x'}; // p3 may now point to the memory pointed to by p2(p1)
    *p2 = 999;                // THIS MAY CAUSE TROUBLE!!
    cout << *p3 << '\n';      // May not print x
}

void doubleDel() // BAD CODE!!!
{
    int *p = new int[1000]; // acquire memory
    // use *p
    delete[] p; // RELEASE MEMERY

    //wait a while

    delete[] p; // doubleDel() doesnt own * p !!!
}

/*
    * Vector keeps its elements on the free store, but handles all allocation and deallocation.
*/
void f(const string &s)
{
    vector<char> v;
    for (auto c : s)
        v.push_back(c);
};

// reverse
string reverse(const string &s)
{
    string ss;
    for (int i = s.size() - 1; 0 <= i; --i)
        ss.push_back(s[i]);
    return ss;
};

void stuff(int n)
{
    int *p1 = new int[n]; // potential trouble
    unique_ptr<int[]> p2{new int[n]};

    //

    if (n % 2)
        throw runtime_error("odd");
    delete[] p1; // We may never get here
};
