#include <iostream>
#include <queue>

/*
 * Implementing the queue ADT, but each piece of data is paired with a priority value.
 * These priority values need to be inherently comparable, so numbers are usually the choice here.
 * Supports all queue functions, but removes the value with the HIGHEST priority.
 *      - In C++, this is the LARGEST element
 *
 * A good example of this is a safety dispatch. Obviously, all emergencies should and need to be tended to.
 * However, something like a raging fire or fatal situation is more of a priority over maintenance or a non-fatal injury.
 * 
 * In C++, this is another containerized structure. It's part of the queue header file.
 *
 * Associated functions:
 *      - push() - O(log n)
 *      - pop() - O(log n)
 *      - size() - O(1)
 *      - top() - O(1)
 *      - emplace - O(1)
 * 
 */

int main() {
    std::priority_queue<int> pq {};
    pq.push(1);
    pq.push(10);
    pq.push(11);
    pq.push(5);
    std::cout<<pq.top()<<std::endl; // expected output: 11
    return 0;
}
