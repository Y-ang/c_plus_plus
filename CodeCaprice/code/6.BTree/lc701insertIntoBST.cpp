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
        TreeNode* cur = root;
        while (cur) {
            if (val > cur->val && cur->left) {
                cur = cur->left;
            } else if (val > cur->val && !cur->left) {
                cur->left =new TreeNode(val);
                break;
            }
            if (val < cur->val && cur->right) {
                cur = cur->right;
            } else if (val < cur->val && !cur->right) {
                cur->right =new TreeNode(val);
                break;
            }
            if (!cur->left && !cur->right) {
                if (cur->val < val) cur->right = new TreeNode(val);
                else cur->right = new TreeNode(val);
            }
        }
        return root;
    }
};