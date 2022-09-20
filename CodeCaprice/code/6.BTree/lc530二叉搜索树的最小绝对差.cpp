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
    int res = INT_MAX;
    // vector<int> inorderSeq;
    TreeNode* pre;

    int getMinimumDifference(TreeNode* root) {
        // 先得到中序遍历序列，再找最小差值
        // traverse(root);
        // for (int i = 1; i < inorderSeq.size(); i++) {
        //     int diff = inorderSeq[i] - inorderSeq[i - 1];
        //     if (diff < res) {
        //         res = diff;
        //     }
        // }
        // return res;

        // // 在中序遍历的过程中比较差值的大小
        if (root == nullptr) return res;
        getMinimumDifference(root->left);
        if (pre && root->val - pre->val < res) res = root->val - pre->val;
        pre = root;
        getMinimumDifference(root->right);
        return res;

        // 迭代的方法进行中序遍历
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (pre) res = min(res, root->val - pre->val);
            pre = root;
            root = root->right;
        }
        return res;


    }

};