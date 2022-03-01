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
    int postIndex;
    unordered_map<int, int> inorderMap;  
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        int index = 0;
        for (auto& val : inorder) {
            inorderMap[val] = index++;
        }
        TreeNode* root = traverse(0, inorder.size() - 1, postorder);
        return root;
    }
    TreeNode* traverse(int inLeft, int inRight, vector<int> postorder) {
        if (inLeft > inRight) return nullptr;
        int rootVal = postorder[postIndex];
        int index = inorderMap[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        postIndex--;
        root->right = traverse(index + 1, inRight, postorder);
        root->left = traverse(inLeft, index - 1, postorder);
        return root;
    }
};