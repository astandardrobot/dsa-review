#include <iostream>
#include <vector>

/*
 * Fibonacci uses...fibonacci numbers to find a value within a sorted array.
 * It's a divide and conquer algorithm, similar to that of a binary search algorithm.
 * Moreover, the complexity of a Fibonacci search is also O(log(n))
 *
 * However, unlike how the binary search DIVIDES a structure evenly,
 * a fibonacci search splits a structure in various ways, using ADD and SUBTRACT
 * operators.
 *
 */

int findmin(int x, int y) {
    if(x <= y) return x;
    else return y;
}

int fibonacci(std::vector<int>& vec, int target, int n) {
    int fibK1 = 0, fibK2 = 1;
    int fibK = fibK1 + fibK2;

    while(fibK < n) {
        fibK2 = fibK1;
        fibK1 = fibK;
        fibK = fibK2 + fibK1;
    }
    int offset = -1;

    while(fibK > 1) {
        int index = findmin(offset+fibK2, n-1);
        if(vec[index]) {
            fibK = fibK1;
            fibK1 = fibK2;
            fibK2 = fibK - fibK1;
            offset = index;
        } else if(vec[index] > target) {
            fibK = fibK2;
            fibK1 = fibK1 - fibK2;
            fibK2 = fibK - fibK1;
        } else return index;
    }
    if(fibK1 && vec[offset+1] == target) return offset+1;
    return -1;
}

int main() {
    std::vector<int> testvec { 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100,235};
    int find = fibonacci(testvec, 235, testvec.size()-1);
    if(find >= 0) {
        // expected output: Found at index: 11
        std::cout<<"Found at index: "<<find;
    }
    return 0;
}
