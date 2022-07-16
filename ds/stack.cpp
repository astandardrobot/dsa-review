#include <iostream>
#include <stack>

/*
 * Stacks follow a LIFO access policy (last-in-first-out). This means that we can push 
 * This container is a bit interesting, since it likely uses a list, deque, or vector as an underlying container
 *
 * Associated functions include:
 *      - pop() - removal from the foremost point on the stack: O(1)
 *      - push() - insertion to the bottommost point on the stack: O(1)
 *      - peek() or top() - returns the value of the foremost member of the stack: O(1)
 *      - size() - I believe it's something like isFull() and isEmpty()? Checks the stack's capacity in these respects: O(1)
 *      - empty() - clears the stack: O(1)
 *
 * Use cases:
 *      - Expression evaluation and syntax parsing.
 *      - Finding the correct path in a maze using backtracking.
 *      - Runtime memory management.
 *      - Recursion function (i.e. Tower of Hanoi)
 */

template <typename T>
void print_array(T &v) {
    for(auto i : v) {
        std::cout<<i<<' ';
    }
    std::cout<<'\n';
}

int main() {
    std::stack<int> newStack;
    std::stack<int> newStack2;

    newStack.push(1);
    newStack.push(2);
    newStack.emplace(3);

    newStack2.push(4);
    newStack2.push(5);
    newStack2.push(6);

    std::cout<<(newStack.top());
    newStack.swap(newStack2);
}
