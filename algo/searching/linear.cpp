#include <iostream>
#include <vector>

/*
 * Linear search
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
