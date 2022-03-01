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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = traverse(nums, 0, nums.size() - 1);
        return root;
    }
    TreeNode* traverse(vector<int> nums, int left, int right) {
        int maxIndex = getMaxIndex(nums, left, right);
        if (maxIndex == -1) return nullptr;
        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = traverse(nums, left, maxIndex - 1);
        root->right = traverse(nums, maxIndex + 1, right);
        return root;
    }
    int getMaxIndex(vector<int> nums, int left, int right) {
        int max = -1;
        int maxIndex = -1;
        for (int i = left; i <= right; i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};