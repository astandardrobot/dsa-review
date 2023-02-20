/*
 * Arrays hold the same type of data contiguously in memory (i.e. next to one another)
 * Array sizes ae the product of the size of an element stored in it by the amount of elements in it.
 * On a higher level, arrays, along with most data structures, should have functions that enable
 * ACCESSING and MODIFYING the structure's contents. 
 */

#include <iostream>
/*
 * C++'s "stock" implementation of an array is essentially a super minimalist wrapper around the C implementaiton of an
 * array. The array implementation found in the stdlib is generally more dynamic, as it doesn't decay to a pointer when
 * passed into a function. Moreover, it provides the same functionality and syntactically, it's better aligned with other 
 * basic data structures.
 * 
 * Complexities:
 *      - arr[index]: O(1)
 *      - arr[index] = val [beginning]: O(n), [middle]: O(n), end: O(1) -> provided that the array isn't full
 *
 * Use cases:
 *      - Easy, quick access
 *      - Knowing the size of the input before implementation
 *      - Fast iteration
 */
#include <array>

// A simple template to print the values of an array
template <typename T>
void print_array(T &v) {
    for(auto i : v) {
        std::cout<<i<<' ';
    }
    std::cout<<'\n';
}

// Arrays declared outside of a function are initialized. Zeroes will be placed in each index for primitive types.
int foobar[10];
std::array<int,10>fubar;

int main() { 
    // Arrays cannot be dynamically sized. Thus, their size needs to be considered upon declaration.
    int foo[4]; 

    // By default (in cpp), arrays are uninitialized by default. However, we can create "empty" arrays by using
    int bar[100] = {};
    // cpp has allowed for a universal initialization for arrays, removing the need of an =
    int bar2[100] {};

    print_array(foo);

    // To index an array, use the simple array[index num] syntax intuitive in most languages
    // The time complexity of this is O(1). If you know the address of the value, you can access it easily.
    // The address of an element in memory will be the base address of the array plus the index times 
    // the size of the element in the array
    foo[0] = 84; // Arrays (as well as most other structures) are zero indexed. The first index is array[0]

    // Searching an array has a complexity of O(n), worst-case. The value could be at the very end of the array,
    // forcing the program to pass through the entire length of the array.
    for(int i = 0; i < sizeof(foo)/sizeof(foo[0]); i++) {
        std::cout<<foo[i]<<std::endl;
    }

    // Strings are just arrays of characters, so with the basic implementation (derived from C)...
    char hello[6] {'H','e','l','l','o','\n'};

    /* Passing in an array, vector, etc. as an argument is slightly confusing
     * Here's some examples of passing them in as a pointer vs. reference
     */
    void newFunc1(int * x);
    void newFunc2(int x[100]);
    void newFunc3(int x[]);
    void newFunc4(std::array<int,4> *y);

    void refFunc(int (&myArr)[100]);
    void refFunc2(std::array<int,100>&myArrray);
    /* First, passing the array as a pointer disallows getting any size info for the array
     * Moreover, references avoid the expense of copying the array. 
     */

    // Lastly, arrays can be multidimensional
    int multistuff[10][20];
    std::array<std::array<int,4>,4>newArr {};
    // These aren't limited to two dimensions, either
    int multistuff2[10][20][30][40];
    std::array<std::array<std::array<int,4>,4>,4>newArr2 {};
}
