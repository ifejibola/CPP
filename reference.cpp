
#include <iostream>
using namespace std;

void f()
{
    string author = "Samuel Clemens";
    string &penName = author; // penName is an alias for author
    penName = "Mark Twain";   // now auhtor = "Mark Twain"
    cout << author;           //outputs "Mark Twain"
};

/*
    References are most ofteen used for passing function arguments and are also often used for
    returning results from functions.
*/