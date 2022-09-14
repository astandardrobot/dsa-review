#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node* next;
};

/*
 * Given two linked lists, determine whether one's values are a subset of the other.
 *
 * Follows a few simple steps:
 *      - Take first node of the second list
 *      - Start matching the corresponding nodes of the first list
 *      - If they match through and through, return true
 *      - Else break the iteration, and start comparing the first list's
 *        first node with the second list's second node
 *      - Recurse
 *      - If list one is empty, sublist = found. Otherwise, return false
 */

bool sublist(Node* first, Node* second) {
    Node* ptr1 = first, *ptr2 = second;
    // Basic checks: if the first and second pointers are null, they are equal, thus true.
    if(first == nullptr && second == nullptr) return true;
    // if one of the lists has a Node and the other one doesn't, immediately return false
    if(first == nullptr || first != nullptr && second == nullptr) return false;
    
    // Until we reach the end of the second list
    while(second != nullptr) {
        // keep track of the iteration
        ptr2 = second;
        // until we reach a null pointer in the first
        while(ptr1 != nullptr) { 
            // if the second list node at this point is null, the subs aren't equal
            if(ptr2 == nullptr) return false;
            // if the first's data == the second's data, move the pointers to the next nodes
            else if(ptr1->data == ptr2->data) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            // otherwise get outta here
            else break;
        }
        // some more checks
        if(ptr1 == nullptr) return true;
        ptr1 = first;
        second = second->next;
    }
    return false;
}

int main() {
    return 0;
}
