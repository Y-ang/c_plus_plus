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
    int min = INT_MAX;
    vector<int> inorderSeq;

    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        for (int i = 1; i < inorderSeq.size(); i++) {
            int diff = inorderSeq[i] - inorderSeq[i - 1];
            if (diff < min) {
                min = diff;
            }
        }
        return min;

    }
    void traverse(TreeNode* node) {
        if (!node) return;
        traverse(node->left);
        inorderSeq.push_back(node->val);
        traverse(node->right);
    }
};