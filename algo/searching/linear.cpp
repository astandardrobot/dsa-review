#include <iostream>
#include <vector>

/*
 * Linear search
 * This is fairly straightforward. Go through the array from beginning to end.
 * If the value = the target, return the value
 * Otheweise, return -1
*/
int linearSearch(std::vector<int> &v, int x) {
    for(int i = 0; i <= v.size(); i++) {
        if(v[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    return 0;
}
