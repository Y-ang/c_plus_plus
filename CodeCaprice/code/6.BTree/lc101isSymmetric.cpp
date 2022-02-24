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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return cmp(root->left, root->right);
        
    }
    bool cmp(TreeNode* nodeLeft, TreeNode* nodeRight) {
        if (!nodeLeft && !nodeRight) return true;
        if (!nodeLeft || !nodeRight) return false;
        return nodeLeft->val == nodeRight->val && cmp(nodeLeft->left, nodeRight->right) && cmp(nodeLeft->right, nodeRight->left);
    }
};
