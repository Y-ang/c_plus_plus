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
    //方法一
    int sum = 0;
    //方法二
    vector<int> inorderSeq;
    int index = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        //方法一：右中左 二叉搜索树的逆序递归
        if (root == nullptr) return root;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;

        // 方法二：借助辅助数组，计算出结点和，再赋值
        inorderTraverse(root);
        for (int i = inorderSeq.size() - 2; i >= 0; i--) {
            inorderSeq[i] += inorderSeq[i + 1];
        }
        changeVal(root);
        return root;
    }
    void inorderTraverse(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraverse(root->left);
        inorderSeq.push_back(root->val);
        inorderTraverse(root->right);
    }
    void changeVal(TreeNode* root) {
        if (root == nullptr) return;
        changeVal(root->left);
        root->val = inorderSeq[index++];
        changeVal(root->right);
    }
};