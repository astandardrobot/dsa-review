#include <iostream>
#include "binary_tree.hpp"

/*
* Binary Search Trees are common derivative of a binary tree with these characteristics
*
* A left subtree of a given node must contain values < the parent value
* A right subtree of a given node must contain values > the parent value
* Both left and right subtrees also have to be binary search trees.
*
* The structure's name can be attributed to the search algorithm below: a binary search.
* Assuming the tree is balanced (the left and right subtree heights are <= 1), we reduce the size of the search to n/2, n/4, etc.
*   
*/

Node<int>* search(Node<int>* parent, int key) {
    if(parent == nullptr || parent->key == key) {
        return parent;
    }
    if (parent->key < key) {
        return search(parent->right, key);
    }
    return search(parent->left, key);
} 

int main() {
    return 0;
}
