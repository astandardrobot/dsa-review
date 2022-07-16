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
 * SelectionSort: Finding the minimum value in an array and placing it at the front.
 * For example, look at the minimum element in vector [0...n] and place it at the beginning of [0...n]
 * Next, look at the minimum element in the same vector and place it at the beginning of [1...n]
 * etc., etc.
 *
 * Time complexity: Still O(n^2) like the bubble sort, but 
*/
void selectionSort(std::vector<int>&v) {
    for(int i = 0; i < v.size()-1; i++) {
        int min = i;
        for(int j = i+1; j < v.size(); j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
        newSwap(&v[min], &v[i]); 
    }
}

int main() {
    std::vector<int>v2 = {300,5,1029,-1,-4,80,53,582};
    selectionSort(v2);
    std::cout<<"Selection Sort: ";
    print_array(v2);
}