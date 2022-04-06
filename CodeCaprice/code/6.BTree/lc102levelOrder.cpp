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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> nodes;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                nodes.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            res.push_back(nodes);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();     // 当前层的节点数
            vector<int> level(size);  // 保存当前层的节点值

            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();   // 从队列中获取当前层的节点
                que.pop();
                level[i] = cur->val;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            res.push_back(level);
        }
        return res;
    }