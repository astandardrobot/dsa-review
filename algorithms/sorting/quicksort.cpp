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
 * A QuickSort algorithm is a divide and conquer process. It chooses one element in the structure as a pivot element
 * From here, it will place all elements < the pivot to the left. Similarly, elements > the pivot are to the right.
 *
 * The partition function is an important part of the QuickSort algorithm. This takes the LAST element of the
 * vector, places it in the correct position, and moves smaller to the left and greater to the right.
 */
int partition(std::vector<int> &v, int low, int high) {
    int pivot = high;
    int firstIndex = low;
    for(int i = low; i < high; i++) {
        if(v[i] < v[pivot]) {
            newSwap(&v[i], &v[firstIndex]);
            firstIndex++;
        }
    }
    newSwap(&v[firstIndex], &v[pivot]);
    return(firstIndex);
}

/*
 * The QuickSort function essentially performs partitions recursively across two halves of the
 * vector while low < high
 */
void quickSort(std::vector<int>&v, int low, int high) {
    if(low<high) {
        int pivot = partition(v,low,high);
        quickSort(v,low,pivot-1);
        quickSort(v,pivot+1,high);
    }
}

int main() 
{ 
    std::vector<int> v { 1 , 10 , 11 , 9 , 14 , 3 , 2 , 20 , 19 };
    std::cout<<"Vector Before Sorting: "<<std::endl;
    print_array(v);
    quickSort(v, 0, v.size()-1); 
    std::cout << "Sorted vector: \n"; 
    print_array(v); 
    return 0; 
}
