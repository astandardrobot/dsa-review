#include <iostream>
#include <vector>

/*
 * Binary search
 */

int binarySearch(std::vector<int> &v, int x) {
    int left = 0; int right = v.size()-1;
    while(left<right) {
        int mid = left+(right-left)/2;
        if(x == v[mid]) {
            return mid;
        } else if(x>v[mid]) {
            left = mid +1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}
