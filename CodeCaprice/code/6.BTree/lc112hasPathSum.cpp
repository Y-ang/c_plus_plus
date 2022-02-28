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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // DFS
        // int sum = 0;
        // return traverse(root, sum, targetSum);

        // BFS
        queue<TreeNode*> queNodes;
        queue<int> queSum;
        if (root) {
            queNodes.push(root);
            queSum.push(root->val);
        } 
        while (!queNodes.empty()) {
            TreeNode* cur = queNodes.front();
            queNodes.pop();
            int sum = queSum.front();
            queSum.pop();
            if (sum == targetSum && !cur->left && !cur->right) return true;
            if (cur->left) {
                queNodes.push(cur->left);
                queSum.push(sum + cur->left->val);
            }
            if (cur->right) {
                queNodes.push(cur->right);
                queSum.push(sum + cur->right->val);
            }
        }
        return false;

    }

    int traverse(TreeNode* node, int sum, int targetSum) {
        if (!node) return false;
        sum += node->val;
        if (!node->left && !node->right && targetSum == sum) return true;
        return traverse(node->left, sum, targetSum) || traverse(node->right, sum, targetSum);
    }
};