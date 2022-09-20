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
    TreeNode* searchBST(TreeNode* root, int val) {
        // DFS
        if (!root || root->val == val) return root;
        TreeNode* node;
        if (root->val > val) node = searchBST(root->left, val);
        if (root->val < val) node = searchBST(root->right, val);
        return node;

        // BFS
        // TreeNode* cur = root;
        while (root) {
            if (root->val == val) return root;
            else if (root->val > val) root = root->left;
            else root = root->right;
        }
        return cur;
    }
};