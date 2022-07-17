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
 * If the value is in the lower half, constrain the search to the lower half in the next run
 * If the value is in the upper half, constrain the search to the higher half in the next run
 *
 * Repeatedly do this
 * Return -1 if the target cannot be found (or whatever the exercise asks you to return)
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
