#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
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

/*
这里就把二叉搜索树中删除节点遇到的情况都搞清楚。

有以下五种情况：

第一种情况：没找到删除的节点，遍历到空节点直接返回了
找到删除的节点
第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。

*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 递归法
        if (root == nullptr) return root;
        if (root->val == key) {
            if (!root->left) {
                auto node = root->right;
                delete root;
                return node;
            }
            if (!root->right) {
                auto node = root->left;
                delete root;
                return node;
            }
            // 左右节点皆不为空
            TreeNode* leave = root->right;
            while (leave->left) {
                leave = leave->left;
            }
            leave->left = root->left;
            auto node = root->right;
            delete root;
            return node;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;

        // 迭代法
        // TreeNode* cur = root;
        // TreeNode* parent = nullptr;
        // while (cur != nullptr) {
        //     if (key == cur->val){
        //         break;
        //     } 
        //     parent = cur;
        //     if (key < cur->val) {
        //         cur = cur->left;
        //     } else {
        //         cur = cur->right;
        //     }
        // }
        // // 删除头节点
        // if (parent == nullptr) {
        //     return deleteCurNode(cur);
        // }
        // if (parent->left && parent->left->val == key) {
        //     parent->left = deleteCurNode(cur);
        // } else if (parent->right && parent->right->val == key) {
        //     parent->right = deleteCurNode(cur);
        // }
        // delete cur;
        // return root;
    }
    TreeNode* deleteCurNode(TreeNode* node) {
        if (node == nullptr) return nullptr;
        if (!node->left && node->right) {
            return node->right;
        } else if (node->left && !node->right) {
            return node->left;
        } else if (node->left && node->right) {
            TreeNode* leave = node->right;
            while (leave->left != nullptr) {
                leave = leave->left; 
            }
            leave->left = node->left;
            return node->right;
            // delete tmp;
        }
        return nullptr;

    }

};

 int main() {
    Solution su;
    TreeNode* leave1 = new TreeNode(2);
    TreeNode* leave2 = new TreeNode(4);
    TreeNode* leave4 = new TreeNode(7);
    TreeNode* nodeL = new TreeNode(3, leave1, leave2);
    TreeNode* nodeR = new TreeNode(6, nullptr, leave4);
    TreeNode* root = new TreeNode(5, nodeL, nodeR);
    int key = 3;
    su.deleteNode(root, key);
    return 0;
 }

// 普通二叉树的删除方式
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            if (root->right == nullptr) { // 这里第二次操作目标值：最终删除的作用
                return root->left;
            }
            TreeNode *cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            swap(root->val, cur->val); // 这里第一次操作目标值：交换目标值其右子树最左面节点。
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};