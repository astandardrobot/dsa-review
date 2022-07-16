#include <iostream>
#include <deque>

/*
 * Stack: LIFO - essentially adding and removing from one side
 * Queue: FIFO: Adding from one side and removing from the other
 * Deque: Adding and removing from both sides of the structure
 *      - This means it supports both LIFO and FIFO policies
 * This is another containerized structure in C++.
 *
 * Associated functions:
 *      - front(), back(), at(), operator[] - O(1)
 *      - push_front(), push_back(), pop_front(), pop_back() - O(1)
 *      - insert(), emplace() - O(n), if not at the front or end
 *
 *
 */

int main() {
    std::deque<int> d {};
    auto it = d.begin();
    d.push_front(1);
    d.push_back(10);
    d.emplace(it+1, 2);
    d.insert(it+2,3);
    d.pop_back();
    d.pop_front();
}
