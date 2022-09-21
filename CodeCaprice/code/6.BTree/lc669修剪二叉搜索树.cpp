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

/*
递归
如果root（当前节点）的元素小于low的数值，那么应该递归右子树，并返回右子树符合条件的头结点。
如果root(当前节点)的元素大于high的，那么应该递归左子树，并返回左子树符合条件的头结点。

否则，分别处理做左子树和右子树；处理完左子树的结果赋给root->left，处理完右子树的结果赋给root->right

迭代
在剪枝的时候，可以分为三步：
将root移动到[L, R] 范围内，注意是左闭右闭区间
剪枝左子树
剪枝右子树

*/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {

        // 简洁版递归法
        if (root == nullptr) return root;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;

        // 迭代法
        if (!root) return nullptr;

        // 处理头结点，让root移动到[L, R] 范围内，注意是左闭右闭
        while (root != nullptr && (root->val < L || root->val > R)) {
            if (root->val < L) root = root->right; // 小于L往右走
            else root = root->left; // 大于R往左走
        }
        
        // 此时root已经在[L, R] 范围内，处理左孩子元素小于L的情况
        TreeNode *cur = root;
        while (cur != nullptr) {
            while (cur->left && cur->left->val < L) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }

        // 此时root已经在[L, R] 范围内，处理右孩子大于R的情况
        cur = root;
        while (cur != nullptr) {
            while (cur->right && cur->right->val > R) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }

};