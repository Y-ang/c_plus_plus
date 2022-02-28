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
    int sumOfLeftLeaves(TreeNode* root) {
        // dfs
        // int sum = 0;
        // sumLeft(root, sum);
        // return sum;

        // bfs
        queue<TreeNode*> que;
        vector<int> nodes;
        int sum = 0;
        if (root) que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur -> left) {
                if (isLeave(cur->left)) {
                    sum += cur->left->val;
                } else {
                    que.push(cur->left);
                }
            }
            if (cur->right) {
                que.push(cur->right);
            }
        }
        return sum;
        
    }
    int sumLeft(TreeNode* root, int& sum) {
        if (root == nullptr) return 0;
        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
        } 
        return sumLeft(root->left, sum) + sumLeft(root->right, sum);
    }

    bool isLeave(TreeNode* node) {
        return !node->left && !node->right;
    }
};