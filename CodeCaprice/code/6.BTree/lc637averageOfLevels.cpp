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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                sum += cur->val;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            res.push_back(sum/size);
        }
        return res;
    }
};