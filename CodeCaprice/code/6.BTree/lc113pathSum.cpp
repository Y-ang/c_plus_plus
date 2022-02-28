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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // dfs
        vector<vector<int>> res;
        vector<int> path;
        traverse(root, targetSum, path, res);
        return res;
    }
    void traverse(TreeNode* node, int targetSum, vector<int> path, vector<vector<int>>& res) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right && targetSum == node->val) {
            res.push_back(path);
            return;
        }
        traverse(node->left, targetSum - node->val, path, res);
        traverse(node->right, targetSum - node->val, path, res);
    }
};