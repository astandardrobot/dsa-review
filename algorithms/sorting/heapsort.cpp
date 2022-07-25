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
 * Heapify algorithm: Converts a binary tree into a COMPLETE binary tree
 * A complete binary tree is filled at every level except (possibly) the last.
 * All nodes tend towards the left.
 *
 * PSEUDOCODE:
 *      Root = array[0];
 *      Largest = largest(array[0] , array[2*0+1], array[2*0+2]);
 *      if(Root != Largest) {
 *          newSwap(Root, Largest)
 *      }
*/
template<typename T>
void maxHeapify(T &v, int root, int size_) {
    int largest, x = (2*root)+1, y=x+1;
    
    if(x < size_ && v[x] > v[root])
        largest = x;
    else
        largest = root;
    if(y < size_ && v[y] > v[largest])
        largest = y;
    if(largest != root) {
        //std::swap(v[root], v[largest]);
        newSwap(&v[root], &v[largest]);
        maxHeapify(v, largest, size_);
    }
}

template<typename T>
void buildMaxHeap(T &v) {
   for(int i = (v.size() / 2); i >= 0; i--) {
        maxHeapify(v, i, v.size());
   }
}

/*
 * heapSort: comparison-based sorting on a binary heap
 * A binary heap is a completely binary tree in which parent nodes (in this case)
 * are greater than their children.
 * 
*/
void heapSort(std::vector<int>&v) {
    buildMaxHeap(v);
    int sz = v.size();
    for(int i = v.size()-1; i>0; i--) {
        newSwap(&v[0], &v[i]);
        sz--;
        maxHeapify(v, 0, sz);
    }
}

int main() {
    std::vector<int> v6 = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heapSort(v6);
    std::cout<<"Max heap sort: ";
    print_array(v6);
}
