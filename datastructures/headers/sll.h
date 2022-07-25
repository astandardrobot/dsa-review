#include <iostream>
#include <string>
#ifndef _SLL_H
#define _SLL_H
/*
 * Linked lists, hereon referred to as LLs, are linear, non-contiguous data structures. This means that the elements contained aren't neighbors in memory.
 * Essentially, LLs consist of structures, commonly known as nodes, with pointers to other nodes.
 * These can be singly or doubly linked, or even circular.
 *
 * Singly-linked lists can only have pointers to the NEXT node.
 * Since we're constrained to forward traversal, accessing elements is less efficient than in a doubly-linked.
 * Moreover, even if the pointer of the node is given, the complexity for insertion/deletion is O(n).
 *
 * A SLL is best when searching isn't a high priority.
 *
 * Functions usually include something along the lines of:
 *      - push_front() - insertion: O(1)
 *      - push_end() or push_back() - insertion: O(n)
 *      - remove_front() - deletion: O(1)
 *      - remove_end() - deletion: O(n)
 *      - insert() - insertion: O(n)
 *      - search() or get() - accessing: O(n)
 *      - size() and isEmpty() - checking for structure size: O(1)
 *
 * Complexity is GENERALLY O(n), worst-case for most of the LL's functions. Many sites say that insertion/deletion is O(1),  * but that's usually only reserved for the head node
 * or if the traversal hasn't been implemented.
 *
 * Use cases:
 *      - Constant insertion / deletion
 *      - Dynamic resizing
 *      - No random access needed
 *      - Insertion into middle of list
 */
template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node() {
        data = 0;
        next = NULL;
    }
    Node(T x) {
        data = x;
        next = NULL;
    }
};

template <class T>
class SingleLink {
private:
    Node<T> *head;
public:
    bool isEmpty();
    int size();
    void printList();

    void push_front(T val);
    void push_back(T val);
    void insert(T index, T val);
    void remove(T val);

    Node<T> *search(T val);

    // Default onstructor
    SingleLink() {
        head = NULL;
    }
};

#endif

// O(1)
template <class T>
bool SingleLink<T>::isEmpty() {
    if(head == NULL) {return true;}
    else {return false;}
}

// O(n)
template <class T>
int SingleLink<T>::size() {
    int count = 0;
    Node<T> *tmp = head;
    while(tmp != NULL) {
        count += 1;
        tmp = tmp->next;
    }
    return count;
}

// O(n)
template <class T>
void SingleLink<T>::printList() {
    if(head == NULL){std::cout<<"linked list is empty"<<std::endl;}
    std::cout<<std::endl<<"----link list items------"<<std::endl;
    Node<T>* temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<" | ";
        temp = temp->next;
    }
    std::cout<<std::endl<<"--------------------------"<<std::endl;
}


// O(1)
template <class T>
void SingleLink<T>::push_front(T val) {
    Node<T>* newNode = new Node<T>[1];
    newNode->data = val;
    if(head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
        std::cout<<"Added node to front"<<std::endl;
    }
}

// O(n)
template <class T>
void SingleLink<T>::push_back(T val) {
    Node<T>* node = new Node<T>[1];
    node->data = val;
    if(head == NULL) {
        head = node;
        std::cout<<"added a first node"<<std::endl;
    }
    Node<T> *tmp = head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;
    std::cout<<"added a last node"<<std::endl;
}

template <class T>
Node<T> *SingleLink<T>::search(T val) {
    Node<T> *nodeptr = head;
    T res;
    while(nodeptr != NULL && nodeptr->data != val) {
        nodeptr = nodeptr->next;
        res = nodeptr->data;
    }
    std::cout<<"found the node holding "<<res<<std::endl;
    return nodeptr;
}

// O(n)
template <class T>
void SingleLink<T>::insert(T index, T val) {
    if(index > size() || index < 0) {
        std::cout<<"index out of bounds"<<std::endl;
    }
    Node<T> *node = new Node<T>[1];
    node->data = val;
    int count = 0;
    Node<T>* tmp = head;
    while(tmp != NULL && count < index){
        if(count == index-1){
            if(tmp->next != NULL){
                node->next = tmp->next;
            }
            tmp->next = node;
            std::cout<<"new node added at index ["<<index<<"]"<<std::endl;
            break;
        }
        count++;
        tmp = tmp->next;
    }
}

// O(n)
template <class T>
void SingleLink<T>::remove(T index) {
    if(head == NULL) {
        std::cout<<"empty list"<<std::endl;
    }
    if(index >= size() || index < 0) {
        std::cout<<"out of bounds"<<std::endl;
    }
    if(index == 0) {
        head = head->next;
        std::cout<<"removed "<<index<< "from list"<<std::endl;
    } else {
        int count = 0;
        Node<T> *tmp = head;
        while(tmp != NULL) {
            tmp->next = tmp->next->next;
            std::cout<<"item removed at index ["<<index<<"]"<<std::endl;
            break;
        }
        count += 1;
        tmp = tmp->next;
    }
}
