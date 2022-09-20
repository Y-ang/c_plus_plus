#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
 int val;
	struct TreeNode *left;
 	struct TreeNode *right;
    TreeNode(int val_) : val(val_)  {}
 };


class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code herer
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr && root->val == sum) return true;
        return hasPathSum(root->left, sum - root->val) 
                || hasPathSum(root->right, sum - root->val);
    }
};


int main() {
    TreeNode* node = new TreeNode(1);
    Solution su;

    bool res = su.hasPathSum(node, 0);
    cout << res;
    return 0;
}