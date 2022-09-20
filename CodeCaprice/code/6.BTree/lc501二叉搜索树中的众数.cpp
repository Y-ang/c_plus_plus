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
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int maxCnt = -1;
    int cnt = 0;
    TreeNode* pre = nullptr;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        // 递归
        // traverse(root);
        // return res;

        //迭代
        stack<TreeNode*> st;
        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (pre == nullptr) cnt = 1;
            else if (pre->val == root->val) cnt++;
            else if (pre->val != root->val) cnt = 1;
            if (cnt > maxCnt) {
                maxCnt = cnt;
                res.clear();
                res.push_back(root->val);
            } else if (cnt == maxCnt) {
                res.push_back(root->val);
            }
            pre = root;
            root = root->right;
        }
        return res;
    }

    void traverse(TreeNode* node) {
        if (!node) return;
        traverse(node->left);
        if (pre = nullptr)
            cnt = 1;
        else (pre->val == node->val) {
            cnt++;
        } else if (pre->val != node->val){
            cnt = 1;
        }
        pre = node;
        if (cnt > maxCnt) {
            maxCnt = cnt;
            res.clear();
            res.push_back(node->val);
        } else if (cnt == maxCnt) {
            res.push_back(node->val);
        }
        traverse(node->right);
    }
};

int main() {
    Solution su;
    TreeNode* leave = new TreeNode(2);
    TreeNode* right = new TreeNode(2, leave, nullptr);
    TreeNode* root = new TreeNode(1, nullptr, right);
    su.findMode(root);
    return 0;
}