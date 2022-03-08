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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = buildTree(nums, 0, nums.size() - 1);
        return root;
    }
    TreeNode* buildTree(vector<int> nums, int left, int right) {
        if (left > right) return nullptr;
        int midIndex = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[midIndex]);
        root->left = buildTree(nums, left, midIndex - 1);
        root->right = buildTree(nums, midIndex + 1, right);
        return root;
    }
};