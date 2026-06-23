/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_set<int> u;
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        if(abs(left-right) > 1) 
            u.insert(-1);
        else
            u.insert(0);

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        if(u.count(-1)) return false;

        return true;

    }
};
