// in low level code, we occasionally need to store or pass along an address of a memory location
// with out actually knowing what type of object is stoted there. A void* is used for that.
// void* as "pointer to an objec of unknow type"

void f(int *pi)
{
    void *pv = pi; // ok: implicit conversion of int* to void*
    // *pv;           // error can't dereference void

    int *pi2 = static_cast<int *>(pv); // explicit conversion back to int*

    // generall not safe to use a pointer that has been converted("cast") to a type that differs form the type of the obejct pointed to.
}