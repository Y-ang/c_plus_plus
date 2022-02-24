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
    int minDepth(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            res++;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (!cur->left && !cur ->right) return res;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return res;
    }
};