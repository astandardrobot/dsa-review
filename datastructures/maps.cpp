#include <iostream>
#include <map>
#include <unordered_map>

/*
 * Maps, or hashmaps, are key/value structures. No key will have a different value.
 *
 * Associated functions:
 *      - insert() - O(log n)
 *      - find() - O(log n)
 *      - size() - O(1)
 *      - erase() - O(log n)
 *      - emplace() - O(log n)?
 *  These maps can work with keys that have different data types simultaneously.
 *
 *  With a regular map, data is organized in a BST (binary search tree). In an unordered_map, they're organized like a usual hash table.
 * 
 * Associated functions:
 *      - search() - [map] : O(log n), [unordered_map] : O(n) worst case, O(1) average
 *      - insertion() - [map] : O(log n), [unordered_map] : same as search
 *      - deletion() - [map] : O(log n), [unordered_map] : same as search
 *
 */

int main() {
    std::map<int, int> m {};
    std::unordered_map<int,int> um {};

    m.insert(1,2);
    um.insert(1,4);
    um.insert(2,3);
    return 0;
}
