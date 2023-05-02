#include <iostream>
#include "binary_tree.hpp"

/*
* While a binary search tree is useful and common, the search time complexity depends on the shape of the tree.
* ...a binary search tree does not guarantee balance.
*
* This is where a Red-Black tree comes in useful. It's always balanced.
*/

Node<int>* search(Node<int>* node, int key) {
    if(node == nullptr || node->data == key) {
        return node;
    }
    if(key < node->data) {
        return search(node->left, key);
    }        
    return search(node->right, key);
}

int main() {
    return 0;
}
