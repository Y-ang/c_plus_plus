#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
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

// 方法一: travesal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res); 
        return res;
    }
    void traverse(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        traverse(node->left, res);
        res.push_back(node->val);
        traverse(node->right, res);
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;

        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

// 方法三: 统一的迭代法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == nullptr) return {};
        st.push(root);
        while(!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur != nullptr) {
                if (cur->right) st.push(cur->right);
                st.push(cur);
                st.push(nullptr);
                if (cur->left) st.push(cur->left);
            } else {
                res.push_back(st.top()->val);
                st.pop();
            }
        }
        return res;
    }
};

stack<TreeNode*> st;
vector<int> res;
while(!st.empty() || root != nullptr) {
    while(root != nullptr) {
        st.push(root);
        root = root->left;
    }
    root = st.top();
    st.pop();
    res.push_back(root->val);
    root = root->right;
}