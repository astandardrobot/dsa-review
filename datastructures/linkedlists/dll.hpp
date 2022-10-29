#include <iostream>
#ifndef _DLL_H
#define _DLL_H

/*
 * Doubly-linked lists are obviously similar to singly-linked lists. However, they have pointers
 * to both the next and previous nodes, allowing for bidirectional traversal.
 * Despite the similarities, there are a few differences.
 *
 * These are a bit more versatile, yet consume more memory because they ahve one extra pointer.
 * Deletion should be O(1) because the previous nodes can be accessed as easily as the next.
 * Doubly-linked lists are best for heaps, and BSTs.
 *
 * Use cases:
 *      - Easier to delete nodes
 *      - Reverse iteration
 */
template <class T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(T x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
class DoubleLink {
private:
    Node<T> *head;
    Node<T> *tail;
    void reverse();
public:
    bool isEmpty();
    int size();
    void print_forward();
    void print_backward();

    void push_front(T val);
    void push_back(T val);
    void insert(T index, T val);
    void remove_back();
    void remove_front();
    void remove(T val);
    
    Node<T> *search(T val);

    DoubleLink() {
        head = nullptr;
        tail = nullptr;
    }
};

#endif

template <class T>
bool DoubleLink<T>::isEmpty() {
    if(head == nullptr) {std::cout<<"true"<<std::endl; return true;}
    else {std::cout<<"false"<<std::endl; return false;}
}

template <class T>
int DoubleLink<T>::size() {
   int count = 0;
   Node<T> *tmp = head;
   while(tmp != nullptr) {
       count += 1;
       tmp = tmp->next;
   }
   std::cout<<count<<std::endl;
    return count;
}

template <class T>
void DoubleLink<T>::push_front(T val) {
    // Create a new node
    Node<T> *node = new Node<T>[1];
    // the argument will be the value
    node->data = val;
    // since this is the head node, there won't be a previous node.
    node->prev = nullptr;
    // the prior head node will be this new head's next node.
    node->next = head;
    // if there's no head, this is the first node being added to the list.
    if(head == nullptr){
       head = tail = node; 
    } else {
        // otherwise, the old head's previos will be the new head.
        head->prev = node;
        // the node becomes the new head.
        head = node;
    }
    std::cout<<"Added a front node"<<std::endl;
}

template <class T>
void DoubleLink<T>::push_back(T val) {
    Node<T>* node = new Node<T>[1];
    node->data = val;
    if(head == nullptr) {
        head = tail = node;
    }
    Node<T> *tmp = head;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = node;
    tail = node;
    std::cout<<"added a last node"<<std::endl;
}


template <class T>
Node<T> *DoubleLink<T>::search(T val) {
    Node<T> *nodeptr = head;
    T res;
    while(nodeptr != nullptr && nodeptr->data != val) {
        nodeptr = nodeptr->next;
        res = nodeptr->data;
    }
    std::cout<<"found the node holding "<<res<<std::endl;
    return nodeptr;
}

template <class T>
void DoubleLink<T>::insert(T index, T val) {
    if(index > size() || index < 0) {
        std::cout<<"index out of bounds"<<std::endl;
    }
    if(index == 0) {push_front(val);}
    Node<T> *node = new Node<T>[1];
    node->data = val;
    int count = 0;
    Node<T>* tmp = head;
    while(tmp != nullptr && count < index){
        if(count == index-1){
            if(tmp->next != nullptr){
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

template <class T>
void DoubleLink<T>::remove_back(){
    if(head == nullptr){
        std::cout<<"linked list is empty !"<<std::endl;
        return;
    }
    if(head->next == nullptr){
        head = nullptr;
        std::cout<<"last item removed"<<std::endl;
        return;
    }

    Node<T>* tmp = head;
    while(tmp != nullptr){
        if(tmp->next->next == nullptr){
            tmp->next = nullptr;
            std::cout<<"last item removed"<<std::endl;
            break;
        }
        tmp = tmp->next;
        tail = tmp;
    }
            
}

template <class T>
void DoubleLink<T>::remove_front() {
    if(head == nullptr){
        std::cout<<"linked list is empty !"<<std::endl;
        return;
    }
    head = head->next;
    std::cout<<"front item removed"<<std::endl;
}

template <class T>
void DoubleLink<T>::remove(T val) {
    if(head == nullptr){
        std::cout<<"linked list is empty !"<<std::endl;
    }
    if(val >= size() || val < 0){
        std::cout<<"index out of bound !"<<std::endl;
    }
    if(val == 0){
        remove_front();
        std::cout<<"item removed at index "<<val<<std::endl;
    }

    int count = 0;
    Node<T>* tmp = head;
    while(tmp != nullptr){
        if(count == val - 1){
            tmp->next = tmp->next->next;
            std::cout<<"item removed at index "<<val<<std::endl;
            break;
        }
        count++;
        tmp = tmp->next;
    }
}

template <class T>
void DoubleLink<T>::print_forward() {
    if(head == nullptr){std::cout<<"linked list is empty"<<std::endl;}
    std::cout<<std::endl<<"----link list items------"<<std::endl;
    Node<T>* tmp = head;
    while(tmp != nullptr){
        std::cout<<tmp->data<<" | ";
        tmp = tmp->next;
    }
    std::cout<<std::endl<<"--------------------------"<<std::endl;
}

template <class T>
void DoubleLink<T>::print_backward() {
    if(head == nullptr) {std::cout<<"linked list is empty"<<std::endl;}
    reverse();
    print_forward();
}

template <class T>
void DoubleLink<T>::reverse() {
    DoubleLink<T> newList;
    Node<T> *tmp = head;
    while(tmp != nullptr) {
        newList.push_front(tmp->data);
        tmp = tmp->next;
    }
    *this = newList;
}


