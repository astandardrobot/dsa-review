#include <iostream>
#include <vector>
#include <cmath>

/*
 * A jump search is similar to binary searches and interpolation searches: they're good for sorted arrays.
 * Where a jump search gets ahead over a linear search is that it uses intervals to iterate through the array.
     * Let’s consider the following array: (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610). The length of the array is 16. 
     * The Jump search will find the value of 55 with the following steps assming that the block size to be jumped is 4. 
        STEP 1: Jump from index 0 to index 4; 
        STEP 2: Jump from index 4 to index 8; 
        STEP 3: Jump from index 8 to index 12; 
        STEP 4: Since the element at index 12 is greater than 55, we will jump back a step to come to index 8. 
        STEP 5: Perform a linear search from index 8 to get the element 55.
     *
 */

int jumpsearch(std::vector<int>& vec, int target) {
    int n = vec.size();
    
    // Determining the jump interval
    int step = sqrt(n);
    
    // Attewmpt to find the block where the target lies
    int prev = 0;
    while(vec[std::min(step, n)-1]<target) {
        prev = step;
        step += sqrt(n);
        if(prev >= n) return -1;
    }
    
    // Binary search once we find the block
    while(vec[prev] < target) {
        prev += 1;
        if(prev == std::min(step, n)) return -1;
    }
    if(vec[prev] == target) return prev;
    return -1;
}

int main() {
    std::vector<int> test {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
    int res = jumpsearch(test, 55);
    std::cout<<res<<std::endl;
    return 0;
}
