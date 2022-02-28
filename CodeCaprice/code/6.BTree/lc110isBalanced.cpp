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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int depthLeft = depth(root->left);
        int depthRight = depth(root->right);
        if (max(depthLeft, depthRight) - min(depthLeft, depthRight) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + max(depth(node->left), depth(node->right)); 
    }
};