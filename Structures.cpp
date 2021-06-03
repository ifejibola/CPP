#include <iostream>
using namespace std;
/*
    The first step in building a new type is often to organize the elements it needs into a data structure,
    a struct:
*/

struct Vector
{
    int sz;
    double *elem;
};

enum MealType
{
    NO_PREF,
    REGULAR,
    LOW_FAT,
    VEGETARIAN
};

struct Passenger
{
    string name;      //passenger name
    bool isFreqFlyer; // passenger frequent flyer program?
    string freqFlyNo; // the passenger freq. flyer number
};

// Declare and initialize a variable named pass of type Passenget
Passenger pass = {"John DOe", true, "123"};

//access
void changePass(Passenger &pass)
{
    pass.name = "ACE HOOD";
};

void print_addr(Passenger *a)
{
    cout << a->name << '\n';
    cout << a->isFreqFlyer << '\n';
};
// A variable of thpe Vector can defined like this:
Vector v;

void vector_init(Vector &v, int s)
{
    v.elem = new double[s]; // allocate an array of s soubles
    v.sz = s;
}

double read_and_sum(int s)
{
    // read s integers from cin and return thier sum; s is assumed to be positve

    Vector v;
    vector_init(v, s); // allocate s elements for v
    for (int i = 0; i != s; ++i)
        cin >> v.elem[i]; // read into elements

    double sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v.elem[i]; // take the sum of the elements
    return sum;
}

/*
    We use .(dot) to access struct memebers through a name(and through a reference) and -> to
    access struct members through a pointer:
*/
void f(Vector v, Vector &rv, Vector *pv)
{
    int i1 = v.sz;   // access through name
    int i2 = rv.sz;  // access through reference
    int i4 = pv->sz; // access through pointer
}

int main()
{
    char ch = 'Q';
    char *p = &ch;

    Passenger *j;
    j = new Passenger; // j p;oints to the new Passsenger
    j->name = "Luffy"; // set the structure
    j->isFreqFlyer = false;

    delete j;
}