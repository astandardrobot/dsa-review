#include <iostream>
#include <vector>
#include <climits>

/*
 * We'll use an easy Leetcode problem to demonstrate this.
 * 209) Minimum subarray length
 *
 * PROMPT:
 * Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 */

int minSubLength(std::vector<int>& nums, int target) {
    // Establish the minimum sum and current sum variables
    int min_sum = INT_MAX, curr_sum = 0;
    // Init iterators
    int i = 0, j = 0;
    // Iterate through nums
    while(i < nums.size()) {
        // Add the value at the ith index to curr_sum
        curr_sum += nums[i];
        // when / while curr_sum >= the target
        while(curr_sum >= target) {
            // Compare minimum sums in each iteration
            min_sum = std::min(min_sum, i-j+1);
            curr_sum -= nums[i];
            j++;
        }
        i++;
    }
    if(min_sum == INT_MAX) return 0;
    else return min_sum;
}

int main() {
    
}
