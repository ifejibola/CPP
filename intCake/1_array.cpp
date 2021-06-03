/*
    An array organizes itemms sequentially, one after another in memory.

    #STREGNTHS :
        * FAST LOOKUPS: retrieving the elements at a given index takes O(1)time, 
            regardless of the length of the array.

        * FAST APPENDS: Adding a new element at the end of the array take O(1) time, 
            if the array has space.

    #WEAKNESSES:

        * Fixed size. You need to specify how many elements you're going to store in 
        your array ahead of time. (Unless you're using a fancy dynamic array.)
        Costly inserts and deletes. You have to "scoot over" the other elements to fill in
        or close gaps, which takes worst-case O(n) time.
*/
/*

    * Delceare an array that holds 10 integers 

*/
void f()
{
    int gasPrices[10];
    gasPrices[0] = 346;
    gasPrices[1] = 360;
    gasPrices[2] = 354;
};

//INSET