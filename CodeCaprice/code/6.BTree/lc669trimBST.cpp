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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // if (root == nullptr) return root;
        // if (root->val >low && root->val < high) {
        //     root->right = trimBST(root->right, low, high);
        //     root->left = trimBST(root->left, low, high);
        // }
        // if (root->val == high) {
        //     if (root->right) {
        //         root->right = nullptr;
        //     }
        //     if (root->left) root->left = trimBST(root->left, low, high);
        //     return root; 
        // } else if (root->val == low) {
        //     if (root->left) {
        //         root->left = nullptr;
        //     }
        //     if (root->right) root->right = trimBST(root->right, low, high);
        //     return root;
        // } else if (root->val < low) {
        //     root = trimBST(root->right, low, high);
        // } else if (root->val > high) {
        //     root = trimBST(root->left, low, high);
        // }
        
        // return root;

        // // 简洁版递归法
        // if (root == nullptr) return root;
        // if (root->val < low) return trimBST(root->right, low, high);
        // if (root->val > high) return trimBST(root->left, low, high);
        // root->left = trimBST(root->left, low, high);
        // root->right = trimBST(root->right, low, high);
        // return root;

        // 迭代法
        // 先找根节点
        while (root) {
            if (root->val < low) root = root->right;
            else if (root->val > high) root = root->left;
            else break;
        }
        // 修剪根节点的左子树
        TreeNode* cur = root;
        while (cur) {
            while (cur->left && cur->left->val < low) { // 知道cur->left的值大于等于low，才跳出循环
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        // 修剪根节点的右子树
        cur = root;
        while (cur) {
            while (cur->right && cur->right->val > high) { // 直到cur->right值小于等于high才跳出循环
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }

};