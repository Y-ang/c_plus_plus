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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> nodes;
        int bottomLeftValue = 0;
        if (root) que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            bottomLeftValue = cur->val;
            if (cur->right) que.push(cur->right);
            if (cur->left) que.push(cur->left);
        }
        return bottomLeftValue;
    }
};