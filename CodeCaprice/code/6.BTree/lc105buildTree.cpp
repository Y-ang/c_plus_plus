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
    int preIndex;
    unordered_map<int, int> inorderMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        int index = 0;
        for (auto& val : inorder) {
            inorderMap[val] = index++;
        }
        TreeNode* root = traverse(0, inorder.size() - 1, preorder);
        return root;
    }
    TreeNode* traverse(int inLeft, int inRight, vector<int> preorder) {
        if (inLeft > inRight) return nullptr;
        int rootVal = preorder[preIndex];
        int index = inorderMap[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        preIndex++;
        root->left = traverse(inLeft, index - 1, preorder);
        root->right = traverse(index + 1, inRight, preorder);
        return root;

    }
};