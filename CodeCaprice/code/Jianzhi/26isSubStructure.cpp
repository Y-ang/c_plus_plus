#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr || A == nullptr) return false;
        return traverse(A, B) ||  isSubStructure(A->left, B) || isSubStructure(A->right, B);  // 判断当前两树结构是否相同||判断B是不是A的左子树的子结构|| 判断B是不是A的右子树的子结构
    }

    bool traverse(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true; // B 树遍历完整
        if (A == nullptr || A->val != B->val) return false;
        return traverse(A->left, B->left) && traverse(A->right, B->right); // 如果两树的当前节点相同，则遍历下面的节点
    }
};

TreeNode* buildTree(vector<int>& nums, int index) {
    if (index >= nums.size()) return nullptr;
    TreeNode* node = new TreeNode(nums[index]);
    node->left = buildTree(nums, 2 * index + 1);
    node->right = buildTree(nums, 2 * index + 2);
}

int main() {
    vector<int> a = {1,0,1,-4,-3};
    vector<int> b = {1,-4};
    TreeNode* aTree = buildTree(a, 0);
    TreeNode* bTree = buildTree(b, 0);
    Solution su;
    bool res = su.isSubStructure(aTree, bTree);
    cout << res;
    return 0;
}