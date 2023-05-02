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
 * MergeSort is an example of a divide and conquer algorithm. The goal is to take two halves of an array / vector and
 * sort these sections. These sections will be recursively divided until there is only one element left or the 
 * structure is empty, with the intent of merging them at the end.
 *
 * The merge function below is the meat of this algortihm. Essentially, this performs the array division.
 * The MergeSort function just recursively invokes merge to compile the final, sorted structure.
 *
 * The benefit of using a merge sort is that the complexity will usually be O(n log(n)) because it's always going to keep dividing sections. Since merge sorted elements are copied into another vector, the space complexity = O(n)
 *
 * MergeSort is probably the best basic sorting algorithm to use with Linked lists, if you have to sort them
 */
void merge(std::vector<int> &v, int left, int mid, int right) {
    std::vector<int> tmp;
    int firstIdxPtr = left;
    int secondIdxPtr = mid+1;

    while(firstIdxPtr <= mid && secondIdxPtr <= right) {
        if(v[firstIdxPtr] <= v[secondIdxPtr]) {
            tmp.push_back(v[firstIdxPtr]);
            firstIdxPtr++;
        } else {
            tmp.push_back(v[secondIdxPtr]);
            secondIdxPtr++;
        }
    }
    while(firstIdxPtr <= mid) {
        tmp.push_back(v[firstIdxPtr]);
        firstIdxPtr++;
    }
    while(secondIdxPtr <= right) {
        tmp.push_back(v[secondIdxPtr]);
        secondIdxPtr++;
    }
    for(int i = left; i <= right; i++) {
        v[i] = tmp[i-left];
    }
}


void mergeSort(std::vector<int> &v, int start, int end) {
    if(start >= end) return;
    int mid = start + (end - start) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid+1, end);
    merge(v, start, mid, end);
}

int main() {
    std::vector<int> v7 = {6,5,4,3,2,1,0,-12};
    mergeSort(v7, 0, v7.size()-1);
    std::cout<<"MergeSort: ";
    print_array(v7);
}
