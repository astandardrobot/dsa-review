#include <iostream>
#include <vector>

/*
 * Let's say you're trying to find a definition for a word in a dictionary.
 * In a linear fashion, you can start at A and run through it until you get to the target
 *
 * Unless your word is on the first few pages of the As, this is extremely inefficient.
 *
 * Binary searches are great for this, as they start with the middle element.
 * If the value is equal to the target, just return that.
 * If the value is in the upper half, constrain the search to the lower half in the next run
 * If the value is in the lower  half, constrain the search to the higher half in the next run
 *
 * Repeatedly do this
 * Return -1 if the target cannot be found (or whatever the exercise asks you to return)
 */

int binarySearch(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;

    // Return -1 if this isn't a sorted array.
    if(left > right) return -1;
    while(left<right) {
        int mid = left+(right-left)/2;
        if(target == nums[mid]) {
            return mid;
        } else if(target>nums[mid]) {
            left = mid +1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

int recursiveBinary(std::vector<int>& nums, int target, int low, int high) {
    int left = 0, right = nums.size()-1;
    if(left > right) return -1;
    while(left < right) {
        int mid = left+(right-left)/2;
        if(target == nums[mid]) {
            return mid;
        }
        else if(target > nums[mid]) {
            return recursiveBinary(nums, target, mid+1, high);
        } else {
            return recursiveBinary(nums, target, low, mid-1);
        }
    }
    return -1;
}

int main() {
    std::vector<int> nums {1,2,3,4,5,6,7,8};

    std::cout<<"Recursive: "<<recursiveBinary(nums, 4, 0, nums.size()-1)<<std::endl;
    std::cout<<"Binary: "<<binarySearch(nums, 4)<<std::endl;
}
