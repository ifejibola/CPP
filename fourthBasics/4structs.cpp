#include <iostream>
using namespace std;
/*
 * The & in Vector& indicates that we pass v by non-const reference 
    that way, vector_init() can modify the vector passed to it.
   
   * The new operator allocates memory from an area called the free store
     (also known as dynamic memory and heap; §11.2).
*/
struct Vector
{
    int sz;       // number of elments
    double *elem; // pointer to elements
};

//Construct Vector/initialize Vector
void vector_init(Vector &v, int s)
{
    v.elem = new double[s]; // allocate an array of doubles
    v.sz = s;
}

double read_and_sum(int s)
{
    // read s integers from cin and return their sum; s is assumed to be positve
    Vector v;
    vector_init(v, s); // allocate s elements for v
    for (int i = 0; i != s; ++i)
    {
        cout << "Enter a value"
             << "\n";
        cin >> v.elem[i]; // read into elements
    };

    double sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v.elem[i]; //take the sum of the elements
    return sum;
}

/*
We use . (dot) to access struct members through a name (and through a reference) and −> to
access struct members through a pointer.
*/
void f(Vector v, Vector &rv, Vector *pv)
{
    int i1 = v.sz;   //access through name
    int i2 = rv.sz;  //access through reference
    int i4 = pv->sz; // access through pointer
}
int main()
{
    cout << read_and_sum(4);
}