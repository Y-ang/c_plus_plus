#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right (r) {}
};

class Solution {
public:
    TreeNode* ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归1
        // traverse(root, p, q);
        // return ans;

        // 递归2
        if (root == p || root == q || root == nullptr) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        if (!left) return right;
        return left; 
    }

    // 这也是一个后序遍历
    bool traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool cur = root->val == p->val || root->val == q->val;
        bool left = traverse(root->left, p, q);
        bool right = traverse(root->right, p, q);
        if (left && right || (cur && (left || right))) {
            ans = root;
        }
        return left || right || cur;
    }
   
};
int main() {
    Solution su;
    TreeNode le
    su.lowestCommonAncestor();
    return 0;
}