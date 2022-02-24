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
    TreeNode* invertTree(TreeNode* root) {
        // 层次遍历
        // queue<TreeNode*> que;
        // if (root != nullptr) que.push(root);
        // while (!que.empty()) {
        //     int size = que.size();
        //     for (int i = 0; i < size; i++) {
        //         TreeNode* cur = que.front();
        //         que.pop();
        //         TreeNode* tmp = cur->right;
        //         cur->right = cur->left;
        //         cur->left = tmp;
        //         if (cur->left) que.push(cur->left);
        //         if (cur->right) que.push(cur->right);
        //     }
        // }
        // return root;

        // //前序遍历 递归法
        // if (root == nullptr) return root;
        // swap(root->left, root->right);
        // invertTree(root->left);
        // invertTree(root->right);
        // return root;

        // // 前序遍历 迭代法 tongyi
        // stack<TreeNode*> st;
        // if (root != nullptr) st.push(root);
        // while (!st.empty()) {
        //     TreeNode* cur = st.top();
        //     st.pop();
        //     if (cur != nullptr) {
        //         if (cur->right) st.push(cur->right);
        //         if (cur->left) st.push(cur->left);
        //         st.push(cur);
        //         st.push(nullptr);
        //     } else {
        //         swap(st.top()->left, st.top()->right);
        //         st.pop();
        //     }
        // }
        // return root;

        // 前序遍历 迭代
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            swap(cur->right, cur->left);
            st.pop();
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        return root;
    }

};