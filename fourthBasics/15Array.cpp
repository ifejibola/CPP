using namespace std;
#include <iostream>
#include <vector>

/*
    * Array of objects can also be created using new.
*/

char *save_string(const char *p)
{
    char *s = new char[strlen(p) + 1];

    strcpy(s, p); // copy from p to s
    return s;
};

/*
    * Unless you really must use a char* directly the std lib string can be used to simplify save_string()

*/

string save_string2(const char *p)
{
    return string{p};
}

/*
    * To deallocate space allocated by new, delete and delete[] must be able to determine the size of
        the object allocated.

    * Note: a vector is a proper object and can therefore be allocated and deallocated 
        using plain new and dele
*/

void f(int n)
{
    vector<int> *p = new vector<int>(n); // individual object
    int *q = new int[n];                 // ARRAY
};

//WHAT HAPPENS WHEN NEW CAN FIND NO STORE TO ALLOCATE ? BY DEFUALT THE ALLOCATOR
// THROWS A STD bad_alloc exception

void noStore()
{
    vector<char *> v;
    try
    {
        for (;;)
        {
            char *p = new char[100000]; // acquire some memory
            v.push_back(p);             // make sure the new memory is referenced
            p[0] = 'x';                 // use the new memory
        }
    }
    catch (bad_alloc)
    {
        cerr << "Memory exhausted!\n";
    };
}
int main(int argc, char *argv[])
{
    if (argc < 2)
        exit(1);
    char *p = save_string(argv[1]);

    //save 2
    if (argc < 2)
        exit(1);
    string s = save_string(argv[1]);

    //

    delete[] p;
    // The ‘‘plain’’ operator delete is used to delete individual objects; delete[] is used to delete arrays.
}
