#include <iostream>

/*
 * Trees are often implemented like linked lists (i.e. with nodes pointing to other nodes).
 * They're structured similar to a heap 
 */

template <class T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;
};

/*
 * Imagine this tree for a moment.
 * A quick note: trees are most often configured to be binary.
 * Primarily Complete or Full Binary Trees
 * Full:
 *      - Each parent has either 2 or no nodes
 *      - Leaves do not constrained to this
 * Complete:
 *      - Each parent has 2 children
 *      - All nodes are as FAR LEFT as possible
 *      - Every level except the last is completely filled.
 *
 *       1
 *    2     3
 *   8 4   7 6
 *      5
 * We can traverse this tree in a few ways
 *
 * Preorder (root->left->right):
 *      - visit the node (do stuff w the data)
 *      - recursively preorder leftchild
 *      - recursively preorder rightchild
 *      - In the above example: 1,2,8,4,5,3,7,6
 *
 * Postorder (left->right->root):
 *      - recursively postorder leftchild
 *      - recursively postorder rightchild
 *      - visit node
 *      - In the above example: 8,5,4,2,7,6,3,1
 *
 *  Inorder (left->root->right):
 *      - recursively inorder leftchild
 *      - visit node
 *      - recursively inorder rightchild
 *      - In the above example: 8,2,4,5,1,7,3,6
 *
 * These are DEPTH-FIRST traversals. We're taking care of one branch before moving onto the next.
 *
 *
 * 
 */

