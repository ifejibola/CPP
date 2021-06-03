#include <iostream>
#include <array>

using namespace std;
/*
    * A struct is simply a class where the members are public by default. 
    * A struct can have member functions, and constructors.
*/

struct Points
{
    // vector<Point> elem; // must contain at least one OPint
    // Points(Point p0) { elem.push_back(p0); }
};

struct Address
{
    /* data */
    string name;   //'jim
    int number;    // 61
    string street; // south st
    string town;   // new providence
    char state[2];
    char zip[5]; //

    // constructor
    Address(const string n, int nu, const string &s, const string &t, const string &st, int z);
};

Address::Address(const string n, int nu, const string &s, const string &t, const string &st, int z)
    // validate postal code
    : name{n},
      number{nu},
      street{s},
      town{t}
{

    if (st.size() != 2)
        // error("State abbreviation shoul dbe two characters");
        cout << "Error!!";
    // state = {st[0], st[1]}; // store postal code as characters
};

/*
    STRUCTURES AND ARRAYS

    * Naturally, we can have arrays of structs and structs contaning arrays.
 */

struct Poiint
{
    int x, y;
};

Poiint points[3]{{1, 2}, {3, 4}, {5, 6}};
int x2 = points[2].x;

struct Arrayy
{
    Poiint elem[3];
};

Arrayy points2{{1, 2}, {3, 4}, {5, 6}};
// Arrayy points2[] = {{1, 2}, {3, 4}, {5, 6}};
int y2 = points2.elem[2].y;

/*
    * Placing a built-in array in a struct allows us to treat that array as an object:
*/

Arrayy shift(Arrayy a, Poiint p)
{
    for (int i = 0; i != 3; ++i)
    {
        a.elem[i].x += p.x;
        a.elem[i].y += p.y;
    }
    return a;
}

// template <typename T, size_t N>
// struct array
// {
//     T elem[N];

//     T *begin() noexcept { return elem; }
// };

// SHOULD BE USING THE STANDARD LIBRARY
using Arrayy = array<Poiint, 3>; // array of 3 points
Arrayy points{{1, 2}, {3, 4}, {5, 6}};
int x2 = points[2].x;
int y2 = points[2].y;

Arrayy shift2(Arrayy a, Poiint p)
{
    for (int i = 0; i != a.size(); ++i)
    {
        a[i].x += p.x;
        a[i].y += p.y;
    }
    return a;
}

int main()
{

    Arrayy ax = shift(points2, {10, 20});
    cout << y2;
}
