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

int partition(std::vector<int> &v, int l, int h) {
    int part;
    int firstHigh;
    part = h;
    firstHigh = l;
    for(int i = l; i < h; i++) {
        if(v[i] < v[part]) {
            newSwap(&v[i], &v[firstHigh]);
            firstHigh++;
        }
    }
    newSwap(&v[part], &v[firstHigh]);
    return(firstHigh);
}

void quickSort(std::vector<int>&v, int low, int high) {
    int part;
    if(low<part) {
        part = partition(v,low,high);
        quickSort(v,low,part-1);
        quickSort(v,part+1,high);
    }
}