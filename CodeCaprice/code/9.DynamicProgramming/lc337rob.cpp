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
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};


// 后序遍历
class Solution {
public:
    int rob(TreeNode* root) {
        // 后序遍历 + 动态规划
        // 二维数组 保存当前元素选或不选下的最大值
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
    vector<int> robTree(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        // 不取当前点
        int noSteal = max(left[0], left[1]) + max(right[0], right[1]);
        // 取当前点
        int Steal = root->val + left[0] + right[0];
        return {noSteal, Steal};

    } 
};


// 递归
class Solution {
public:
    unordered_map<TreeNode* , int> umap; // 记录计算过的结果
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        if (umap.find(root) != umap.end()) return umap[root];
        // 取当前节点
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
        // 不取当前节点
        int val2 = rob(root->left) + rob(root->right);
        umap[root] = max(val1, val2);
        return max(val1, val2);
    }
};


int main() {

    return 0;
}