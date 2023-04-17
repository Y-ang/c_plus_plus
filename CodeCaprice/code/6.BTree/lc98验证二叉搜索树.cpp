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

// 左子树所有节点小于中间节点，右子树所有节点大于中间节点
// 中序遍历判断是否是递增关系

class Solution {
// private:
//     vector<int> inorderSeq;

public:
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        // 数组 + 查看数组顺序
        // inorderTraverse(root);
        // int flag = true;
        // for (int i = 0; i < inorderSeq.size() - 1; i++) {
        //     if (inorderSeq[i] >= inorderSeq[i + 1]) flag = false;
        // }
        // return flag;

        // 中序遍历
        if (!root) return true;
        bool left = isValidBST(root->left);
        if (pre && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;

        // 迭代法
        TreeNode* pre = nullptr;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();

            if (pre && pre->val >= root->val) return false;
            pre = root;
            
            root = root->right;
        }
        return true;
    }
};