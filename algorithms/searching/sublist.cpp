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
    if(first == nullptr && second == nullptr) return true;
    if(first == nullptr || first != nullptr && second == nullptr) return false;

    while(second != nullptr) {
        ptr2 = second;
        while(ptr1 != nullptr) { 
            if(ptr2 == nullptr) return false;
            else if(ptr1->data == ptr2->data) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else break;
        }
        if(ptr1 == nullptr) return true;
        ptr1 = first;
        second = second->next;
    }
    return false;
}

int main() {
    return 0;
}
