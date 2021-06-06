
using namespace std;
#include <iostream>

int level(int a, int b)
{
    int max;
    if (a <= b)
        max = b;
    else
        max = a;
};

// OR : More directly expressed like
void level2()
{
    int a, b;
    int max = (a <= b) ? b : a;
};

//  error condition

void fct(int *p)
{
    int i = (p) ? *p : runtime_error{"unexprected nullptr"};
};
