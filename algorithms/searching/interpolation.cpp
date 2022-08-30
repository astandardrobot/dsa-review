#include <iostream>
#include <vector>

/*
 * An interpolation search is similar to a jump or binary search, but has the advantage in arrays where
 * values are UNIFORMLY distributed. This function has an average complexity of O(n).
 * The idea of formula is to return higher value of pos when element to be searched is closer to arr[hi].
 * And smaller value when closer to arr[lo]
 */

int interpolation(std::vector<int>& vec, int target) {
    int left = 0, right = vec.size()-1;
    while(left <= right && target >= vec[left] && target <= vec[right]) {
        if(left == right) {
            if(vec[left] == target) return left;
            return -1;
        }
        // Finding a pivot position, ensuring UNIFORM distribution
        int pos = left + (((double)(right-left)/(vec[right] - vec[left])) * (target - vec[left]));
        if(vec[pos] == target) return pos;
        if(vec[pos] < target) left = pos+1;
        else right = pos-1;
    }
    return -1;
}

int main() {
    return 0;
}
