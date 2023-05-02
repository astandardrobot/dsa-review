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
 * bubbleSorting: Super easy to implement, but costly. 
 * It repeatedly swaps adjacent values if they are `not ordered already.
 * The nested for loops causes this function to run at O(n^2).
 * However, this can be slightly optimized by breaking the loop if the inner loop doesn't swap
 * Though generally, especially in interviews, this is used as a brute force solution before moving into
 * more detailed improvements
*/
void bubbleSort(std::vector<int>&v) {
    bool swapped;
    for(int i = 0; i < v.size()-1; i++) {
        for(int j = 1; j < v.size()-i; j++) {
            if(v[j-1] > v[j]) {
                newSwap(&v[j-1], &v[j]);
                swapped = true;
            }           
        }
        if(swapped == false) break;
    }
}

int main() {
    std::vector<int>v = {100,4,23,-1,12,2,56,0,80,200};
    bubbleSort(v);
    std::cout<<"bubble sort: ";
    print_array(v);
}
