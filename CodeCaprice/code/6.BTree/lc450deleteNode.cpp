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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur = root;
        TreeNode* parent = nullptr;
        while (cur != nullptr) {
            if (key == cur->val){
                break;
            } 
            parent = cur;
            if (key < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        // 删除头节点
        if (parent == nullptr) {
            return deleteCurNode(cur);
        }
        if (parent->left && parent->left->val == key) {
            parent->left = deleteCurNode(cur);
        } else if (parent->right && parent->right->val == key) {
            parent->right = deleteCurNode(cur);
        }
        delete cur;
        return root;
    }
    TreeNode* deleteCurNode(TreeNode* node) {
        if (node == nullptr) return nullptr;
        if (!node->left && node->right) {
            return node->right;
        } else if (node->left && !node->right) {
            return node->left;
        } else if (node->left && node->right) {
            TreeNode* leave = node->right;
            while (leave->left != nullptr) {
                leave = leave->left; 
            }
            leave->left = node->left;
            return node->right;
            // delete tmp;
        }
        return nullptr;

    }

};