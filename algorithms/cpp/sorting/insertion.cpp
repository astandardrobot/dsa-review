#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
// Templates
template<typename T>
void print_array(T const(& arr))
{
    for(auto i : arr) {
        std::cout<<i<<' ';
    }
    std::cout<<""<<std::endl;
}

template<typename T>
void newSwap(T *a, T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
}

/*
 * Insertion Sort: Allows for tuning, whch makes this faster in practice.
 * Start with "empty" and move each value into its correct index.
 * Compswap while iterating backwards, we can "bubble" values down to the correct location.
*/
void insertionSort(std::vector<int>&v) {
    for(int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i - 1;

        while(j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j = j -1;
        }
        v[j+1] = key;
    }
}

/*
 * Insertion Sort 2: SEE ABOVE.
 * Uses moves instead of swaps
*/
void insertionSort2(std::vector<int>&v) {
    for(int i = 1; i < v.size(); i++) {
        int x = v[i];
        // move elements higher if they are bigger than v
        for(int j = i; j > 0; j--) {
            if(x < v[j-1]) {
                std::replace(v.begin(), v.end(), x, v[j-1]);
            } else {
                std::replace(v.begin(), v.end(), x, v[j]);
                break;
            }
        }
    }
}

/*
 * Insertion Sort 3: Moving instead of swapping, replacing the inner loop with a while loop,
 * and using a sentinel value to keep track of our place.
 *
 * COMPARES: O(n) + O(n^2), SWAPS: O(n) + O(n^2)
 * Still O(n^2), but our sort is still sensitive to the input data. Unlike a selection sort, though,
 * if the array is already sorted, we can get this time down to O(n) rather than O(n^2).
 *
 * This optimized insertionSort is probably one of the best sorts to use, especially for smaller lists.
*/
void insertionSort3(std::vector<int>&v) {
    // reverse bubble sort pass to bubble the smallest vlaue to the start of the list
    for(int i = v.size()-1; i > 0; i--) {
        if(v[i] < v[i-1]) {
            newSwap(&v[i-1], &v[i]);
        }
        // sentinel value: the smallest value is at the beginning of the list
        // this means that we don't have to check if j > 0
        for(int j = 1; j < v.size(); j++) {
            int x = v[j];
            int k = j;
            while(x < v[k-1]) {
                v[k] = v[k-1];
                k--;
            }
            v[k] = x;
        }
    }
}

int main() {
    std::vector<int>v3 = {100,34,10444,-10,0,134,55,1022};
    insertionSort(v3);
    std::cout<<"Insertion Sort: ";
    print_array(v3);

    std::vector<int>v4 = {4,1,-23,2000,1984,56,178,170,-100};
    insertionSort2(v4);
    std::cout<<"Insertion Sort v2: ";
    print_array(v4);

    std::vector<int>v5 = {5,600,-1,20,15,345,10009,1002};
    insertionSort3(v5);
    std::cout<<"Insertion Sort v3: ";
    print_array(v5);
}