#include<bits/stdc++.h>
using namespace std;
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
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         traverse(root, res);
//         return res;
//     }
//     void traverse(TreeNode* node, vector<int>& res) {
//         if (node == nullptr) return;
//         traverse(node->left, res);
//         traverse(node->right, res);
//         res.push_back(node->val);
//     }
// };
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         if (root == nullptr) return {};
//         stack<TreeNode*> st;
//         vector<int> res;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode* cur = st.top();
//             res.push_back(cur->val);
//             st.pop();
//             if (cur->left) st.push(cur->left);
//             if (cur->right) st.push(cur->right);

//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };

// 方法3: 统一的迭代方法
class Solution {
public:
    vector<int> postorderTraversal (TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur != nullptr) {
                st.push(cur);
                st.push(nullptr);
                if (cur->right) st.push(cur->right);
                if (cur->left) st.push(cur->left);
            } else {
                res.push_back(st.top()->val);
                st.pop();
            }
        }
        return res;
    }
};