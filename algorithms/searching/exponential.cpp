#include <iostream>
#include <vector>

/*
 * The exponential search algorithm is very similar to the binary search one.
 * Instead of immediately conducting a binary search, this algorithm looks for the range
 * the target element is in first.
 *
 * The AVERAGE time complexity of the exponential, like the binary, is O(log(n))
 * The space complexity is O(!)
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

int exponential(std::vector<int>& v, int target) {
    int end = v.size();
    if(v.size() == 0) return -1;
    int index = 1;
    while(index < (end-0)) {
        if(v[index] < target) {
            index *= 2;     
        } else break;
    }
    return binarySearch(v, target);
}

int main() {
    return 0;
}
