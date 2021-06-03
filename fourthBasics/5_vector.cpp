#include <iostream>
#include <vector>
using namespace std;
/*
    * A vector is simply a sequence of elements that you can access by an index.
*/
vector<int> v;

int main()
{
    v = {5, 7, 9, 4, 6, 8}; // vector of 6 ints

    // add two more integers to vector
    v.push_back(27);
    v.push_back(97);

    // print out the vector
    std::cout << "v={ ";
    for (int n : v)
    {
        cout << n << ", ";
    }
    cout << "}; \n";

    // Traversing a Vector

    vector<int> v = {5, 6, 7, 8, 9};
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << '\n';
};