#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> res;
        if(!root) {return res;}
        std::queue<TreeNode*> newqueue;
        newqueue.push(root);
        TreeNode *tmp;
        while(!newqueue.empty()) {
            std::vector<int> lvl;
            for(int i=0; i<newqueue.size();i++) {
                tmp = newqueue.front();
                newqueue.pop();
                lvl.push_back(tmp->val);
                if(tmp->left) {newqueue.push(tmp->left);}
                if(tmp->right) {newqueue.push(tmp->right);}
            }
            res.push_back(lvl);
        }
        return res;
    }
};
