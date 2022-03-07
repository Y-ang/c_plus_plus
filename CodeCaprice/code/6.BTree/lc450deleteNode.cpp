#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

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
        while (cur != nullptr) {
            if (key == cur->val){
                replaceNode(cur);
                break;
            } else if (key < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return root;
    }
    void replaceNode(TreeNode* node) {
        TreeNode* tmp = node;
        if (!node->left && node->right) {
            node = node->right;
        } else if (node->left && !node->right) {
            node = node->left;
        } else if (node->left && node->right) {
            TreeNode* leave = node->right;
            while (leave->left != nullptr) {
                leave = leave->left; 
            }
            leave->left = node->left;
            node = node->right;
            // delete tmp;

        }
        // delete tmp;
        return;
    }
};

 int main() {
    Solution su;
    TreeNode* leave1 = new TreeNode(2);
    TreeNode* leave2 = new TreeNode(4);
    TreeNode* leave4 = new TreeNode(7);
    TreeNode* nodeL = new TreeNode(3, leave1, leave2);
    TreeNode* nodeR = new TreeNode(6, nullptr, leave4);
    TreeNode* root = new TreeNode(5, nodeL, nodeR);
    int key = 3;
    su.deleteNode(root, key);
    return 0;
 }