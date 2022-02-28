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
    vector<string> binaryTreePaths(TreeNode* root) {
        // DFS 递归法
        // vector<string> res;
        // string path;
        // traverse(root, path, res);
        // return res;

        // BFS 迭代法
        vector<string> res;
        queue<string> paths;
        queue<TreeNode*> que;
        if (root != nullptr) {
            que.push(root);
            paths.push(to_string(root->val));
        }
        
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            string path = paths.front();
            paths.pop();
            if (cur->left == nullptr && cur->right == nullptr) {
                res.push_back(path);
            } 
            if (cur->left) {
                paths.push(path + "->" + to_string(cur->left->val));
                que.push(cur->left);
            }
            if (cur->right) {
                paths.push(path + "->" + to_string(cur->right->val));
                que.push(cur->right);
            }
            
        }
        return res;

    }
    void traverse(TreeNode* node, string path, vector<string>& res) {
        path += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(path);
            return;
        }
        if (node->left) traverse(node->left, path + "->", res);
        if (node->right) traverse(node->right, path + "->", res);
        
    }
};