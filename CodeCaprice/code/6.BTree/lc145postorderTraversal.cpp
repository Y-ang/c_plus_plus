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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
    void traverse(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        traverse(node->left, res);
        traverse(node->right, res);
        res.push_back(node->val);
    }
};
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 方法二：中右左遍历后反转数组，左右中
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            res.push_back(cur->val);
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        reverse(res.begin(), res.end());  // 反转
        return res;
    }
};

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