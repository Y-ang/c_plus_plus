#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// 方法一: traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
    void traverse(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        res.push_back(node->val);
        traverse(node->left, res);
        traverse(node->right, res);
    }
};

// 方法二: iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* curNode = st.top();
            res.push_back(curNode->val);
            st.pop();
            if (curNode->right) st.push(curNode->right);
            if (curNode->left) st.push(curNode->left);
        }
        return res;
    }
};

// 方法三: 统一的迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur != nullptr) {
                if(cur->right) st.push(cur->right);
                if(cur->left) st.push(cur->left);
                st.push(cur);
                st.push(nullptr);
            } else {
                res.push_back(st.top()->val);
                st.pop();
            }
        }
        return res;
    }
};

