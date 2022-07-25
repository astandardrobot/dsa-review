#include <iostream>
#include <vector>
/*
 * Vectors are containers similar to Java's ArrayList: It's a list implementation with array-like functionality.
 * Elements in vectors are still stored contiguously (sequence). However, these structures are dynamically sized.
 * Something to note: vectors don't expand or contract for every added or removed element; that's expensive.
 * They usually allocate more memory to account for future growth.
 * Vectors allow for ITERATION, ACCESS, SIZE CHECKS, INSERTION, and REMOVAL
 *
 * Associated functions:
 *      - push_back(): O(1)
 *      - insert(pos, val): O(n);
 *      - erase(): O(n);
 *      - size(): O(1)
 *      - pop_back(): O(1)
 *
 * Use cases:
 *      - Constant time complexity
 *      - Dynamic resizing
 */

template <typename T>
void print_array(T &v) {
    for(auto i : v) {
        std::cout<<i<<' ';
    }
    std::cout<<'\n';
}

int main() {
    // Creating an empty vector.
    std::vector<int> v {}; 
    v.insert(v.begin(), 2);
    v.push_back(120);
    v.push_back(240);
    print_array(v);

    // Vectors can be accessed like arrays
    int val = v[0];
    std::cout<<val<<std::endl; // 120;

    // However, they can also be accessed with the .at() method
    int otherVal = v.at(1);
    std::cout<<otherVal<<std::endl; // 240

    // AFAIK, there's no difference in complexity between these two operations.
    // The .at() function will catch exceptions, though.

    // Let's add and remove some more stuff
    auto newIndex = v.emplace(v.begin()+1, 200);
    print_array(v); // 120, 200, 240

    v.pop_back();
    print_array(v); // 120, 200
    
    auto i = v.insert(v.begin(), 40);
    print_array(v);
    /* In the section above, both emplace() and insert() place an element at the given position, determined with an
     * iterator. emplace() is used more often, especially for non-primitive types because it directly inserts the element
     * rather than using a reference.
     */
    
    // Vectors also have built-in iterators.
    std::cout<<"Using iterators: ";
    for(auto i = v.begin(); i <v.end(); i++) {
        std::cout<<*i<<' ';
    }
    std::cout<<'\n';

    // These iterators are CONSTANT once they're declared, so despite the dynamic allocation, using these iterators
    // can be tedious.
    
    /* COMPLEXITIES:
     * Insertion (tail): O(1)
     * Insertion (arbitrary): O(n), worst-case
     * Insertion (head): O(n), worst-case
     * Remove Head/Index: O(n), worst-case
     * Remove Tail: O(1)
     * Access Index: O(1)
     * Find Object: O(n), worst-case
     */
}
