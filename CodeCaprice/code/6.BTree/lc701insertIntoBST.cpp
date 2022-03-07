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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 迭代法
        // if (root == nullptr) {
        //     root = new TreeNode(val);
        //     return root;
        // }
        // TreeNode* cur = root;
        // TreeNode* parent = cur;
        // while (cur != nullptr) {
        //     parent = cur;
        //     if (cur->val > val) {
        //         cur = cur->left;
        //     } else {
        //         cur = cur->right;
        //     }            
        // }
        // if (parent->val > val) parent->left = new TreeNode(val);
        // else parent->right = new TreeNode(val);
        
        // return root;

        // 递归法
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root; 
    }
    
};