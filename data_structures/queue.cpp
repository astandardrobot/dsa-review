#include <iostream>
#include <queue>
/*
 * Queues follow a FIFO access policy (first-in-first-out). Think of a line for movie tickets. The first person there
 * is the first person to buy a ticket.
 *
 * Associated functions:
 *      - push(): O(1)
 *      - pop(): O(1)
 *      - front(): O(1)
 *      - back(): O(1)
 *      - empty(): O(1)
 *      - size(): O(1)
 *
 * Use cases:
 *      - Traversal of trees and graphs (BFS, DFS, etc.)
 *      - Implementing cache
 */

template <typename T>
void print_array(T &v) {
    for(auto i : v) {
        std::cout<<i<<' ';
    }
    std::cout<<'\n';
}

int main() {
    std::queue<int> q;
    for(int i=0; i<5; i++) {
        q.push(i);
    }

    std::cout<<q.front();
    return 0;
}
