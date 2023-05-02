#include <iostream>
#include <stack>
#include <queue>
#include <vector>

/*
 * DFS and BFS are FOUNDATIONAL. However, these searches are GENERALLY reserved for graphs.
 * The logic behind these searches can be translated to trees, and they're often simpler.
 *
 * With a DFS, there are three types of searches: Inorder, Postorder, and Preorder (referred to as IN, PRE, and POST from hereon out)
 * IN = Left->Root->Right
 * PRE = Root->Left->Right
 * POST = Left->Right->Root
 */

struct TreeNode {
    int data;
    struct TreeNode* left, *right;
};

struct TreeNode* newNode(int data) {
    struct TreeNode* node = new TreeNode;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

class Traversals {
public:
    void lvlOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
    }

    void preOrder(TreeNode* root) {
        if(root == nullptr) return;

        std::stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* current = stk.top();
            stk.pop();
            std::cout<<current->data<<" ";
            if(current->right) stk.push(current->right);
            if(current->left) stk.push(current->left);
        }
        std::cout<<"\n";
    }

    std::vector<int> postOrder(TreeNode* root) {
        std::stack<TreeNode*> stk;
        std::vector<int> res;
        if(root == nullptr) return res;
        
        while(!stk.empty() || root != nullptr) {
            if(root != nullptr) {
                stk.push(root);
                res.push_back(root->data);
                root = root->right;
            } else {
                TreeNode* current = stk.top();
                stk.pop();
                root = current->left;
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    void inOrder(TreeNode* root) {
        if(root != nullptr) {
            std::stack<TreeNode*> stk;
            TreeNode* current = root;
            while(!stk.empty() || current != nullptr) {
                if(current != nullptr) {
                    stk.push(current);
                    current = current->left;
                } else {
                    current = stk.top();
                    stk.pop();
                    std::cout<<current->data<<" ";
                    current = current->right;
                }
            }
        }
        std::cout<<"\n";
    }
};

void test(TreeNode* root) {
    Traversals random;
    random.preOrder(root);
}

void test2(TreeNode* root) {
    Traversals random;
    for(auto& i : random.postOrder(root)) std::cout<<i<<" ";
    std::cout<<"\n";
}

int main() {
    struct TreeNode* root = nullptr;
    root = newNode(5);
    root->left = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->left->left->left = newNode(0);
    root->left->left->right = newNode(2);
    root->right = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(10);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    test(root);
    test2(root);

}

