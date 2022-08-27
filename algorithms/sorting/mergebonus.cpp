/*
 * The mergesort function can also be edited to MERGE two linked lists.
 */
#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

/*
void merge(std::vector<int> &v, int left, int mid, int right) {
    std::vector<int> tmp;
    int firstIndex = left, secondIndex = mid+1;

    while(firstIndex <= mid && secondIndex <= right) {
        if(v[firstIndex] <= v[secondIndex]) {
            tmp.push_back(v[firstIndex]);
            firstIndex++;
        } else {
            tmp.push_back(v[secondIndex]);
            secondIndex++;
        }
    }
    while(firstIndex <= mid) {
        tmp.push_back(v[firstIndex]);
        firstIndex++;
    }
    while(secondIndex <= right) {
        tmp.push_back(v[secondIndex]);
        secondIndex++;
    }
    for(int i = left; i <= right; i++) {
        v[i] = tmp[i-left];
    }
}
 */
Node *mergeTwoLists(Node* l1, Node* l2) {
    // nullptr to avoid ambiguity in method overloading. Not necessary here, but good practice
    if (l1 == nullptr) return l2;
    // also, these two statements serve as a check.
    // if either list is empty, just return the other one, as there's nothing else to merge.
    else if (l2 == nullptr) return l1;
    // If the l1 pointer's value is <= to l2's, recursively call mergeTwoLists using the next one
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    // Same for l2.next
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

/*
void mergeSort(std::vector<int> &v, int start, int end) {
    if(start >= end) return;
    int mid = start + (end - start) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid+1, end);
    merge(v, start, mid, end);
}
*/

Node *mergeKLists(std::vector<Node *> &lists) {
    if (lists.empty()) return nullptr;
    int len = lists.size();
    while (len > 1) {
        for (int i = 0; i < len / 2; ++i) {
            lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
        }
        len = (len + 1) / 2;
    }
    
    return lists.front();
}
