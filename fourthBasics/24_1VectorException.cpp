#include <iostream>
#include <vector>
using namespace std;

/*
    * A typical implementation of vector will consist of a handle holding pointers to the first element,
    * One-past-the-last element, and One-past-the-last allocated space (or the equivalent information represented
    *   as a pointer plus offsets) :
    * 
    * It holds an allocator (here, alloc), from which the vector can acquire memory for its elements.
    * 
    * The default allocator uses new and delete to acquire and release memory.
    * 
    * 
*/

template <class T, class A = allocator<T>>
class vector
{
private:
    T *elem;  // start of allocation
    T *space; // end of element sequence, start of space allocated for possible expansion
    T *last;  //  end of allocated space
    A alloc;  // allocator
public:
    using size_type = unsigned int; // Type used for vector sizes

    explicit vector(size_type n, const T &val = T(), const A & = A());

    vector(const vector &a);       // copy constructor
    vector &operator=(vector &&a); // move assignment

    vector();

    size_type size() const { return space - elem; }
    size_type capacity() const { return last - elem; }
    void reserve(size_type n); // increase capacity to n

    void resize(size_type n, const T & = {}); // increase size to n
    void push_back(const T &);                // Add an element at the end
};

// Changing Size
/*
    * One of the most useful aspects of vector is that we can change its size to suit our needs.

    * The most popular functions for changing size are V.PUSH_BACK(x)

    * Which adds an x at the end of v, and v.resize(s), which makes s the number of leemnts in v.

    * The key to implementaion of such function is reserve(), which : ADDS FREE SPACE at the end 
        of the vector to grow into.
    
    * reserve() increases the capacity() of a vector.

    * If the new allocation is larger than the old, reserve() needs to allocate new memory and move the elements
        into it.
*/

template <class T, class A>
// void vector<T, A>::reserve(size_type newalloc)
// {
//     if (newalloc <= capacity())
//         return;                                      // never decrease allocation
//     vector_base<T, A> b{vb.alloc, newalloc};         // get new space
//     uninitialized_move(elem, elem + size(), b.elem); // move elements
//     swap(vb, b);
// };

void vector<T, A>::push_back(const T &x)
{
    if (capacity() == size())                  // no more free space;  relocate;
        reserve(sz ? 2 * sz : 8);              // grow or start with 8
    vb.alloc.construct(&vb.elem[size()], val); // add val at end
    ++vb.space;                                // increment size
}