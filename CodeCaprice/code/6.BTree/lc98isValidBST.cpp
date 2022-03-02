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

        // 前序遍历
        if (!root) return true;
        bool left = isValidBST(root->left);
        if (pre && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
    // void inorderTraverse(TreeNode* root) {
    //     if (root == nullptr) return;
    //     inorderTraverse(root->left);
    //     inorderSeq.push_back(root->val);
    //     inorderTraverse(root->right);
    // }
};