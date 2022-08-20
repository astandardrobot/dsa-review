#include <iostream>
#include <vector>

/*
 * Linear search
 * This is fairly straightforward. Go through the array from beginning to end.
 * If the value = the target, return the value
 * Otheweise, return -1
*/
template <typename T>
T linearSearch(std::vector<T>& v, T x) {
    if(v.size() == 0) {
        return -1;
    }
    for(int i = 0; i <= v.size(); i++) {
        if(v[i] == x) {
            return i;
        }
    }
    return -1;
}

/*
 * This is essentially the same thing, just a bit more syntactically concise
 */
template <typename T>
T linearSearch2(std::vector<T>& v, T x) {
    for(T var : v) {
        if(var == x) {
            return var;
        }
    }
    return -1;
}

int main() {
    return 0;
}
