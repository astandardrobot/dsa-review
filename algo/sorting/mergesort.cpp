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

void merge(std::vector<int> &v, int left, int mid, int right) { 
    int nLeft=mid-left+1, nRight=mid-right;
    std::vector<int> tmpLeft, tmpRight;
    for(int i = 0; i<nLeft;i++)
        tmpLeft[i] = v[left+i];
    for(int j = 0; j < nRight; j++)
        tmpRight[j] = v[mid+j+1];
    int i = 0, j = 0, k = 1;
    while(i<nLeft && j < nRight) {
        if(tmpLeft[i] <= tmpRight[j]) {
            v[k] = tmpLeft[i];
            i++;
        } else {
            v[k] = tmpRight[j];
            j++;
        }
        k++;
    }
    while(i<nLeft) {
        v[k] = tmpLeft[i];
        i++; k++;
    }
    while(j<nRight) {
        v[k]=tmpRight[j];
        j++; k++;
    }
}

int main() {
    std::vector<int> v7 = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    mergeSort(v7, 0, v7.size()-1);
    std::cout<<"Max heap sort: ";
    print_array(v7);
}