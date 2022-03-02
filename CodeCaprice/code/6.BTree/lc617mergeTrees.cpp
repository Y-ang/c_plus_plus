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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // DFS
        // if (!root2) return root1;
        // if (!root1) return root2;
        // TreeNode* node = new TreeNode(root1->val + root2->val);
        // node->left = mergeTrees(root1->left, root2->left);
        // node->right = mergeTrees(root1->right, root2->right);
        // return node;

        //BFS
        if (!root2) return root1;
        if (!root1) return root2;
        queue<TreeNode*> que;
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        TreeNode* root = new TreeNode(root1->val + root2->val);
        que.push(root);
        que1.push(root1);
        que2.push(root2);
        while (!que1.empty() && !que2.empty()) {
            auto node = que.front(), node1 = que1.front(), node2 = que2.front();
            que.pop();
            que1.pop();
            que2.pop();
            if (node1->left && node2->left) {
                node->left = new TreeNode(node1->left->val + node2->left->val);
                que.push(node->left);
                que1.push(node1->left);
                que2.push(node2->left);
            }
            if (node1->right && node2->right) {
                node->right = new TreeNode(node1->right->val + node2->right->val);
                que.push(node->right);
                que1.push(node1->right);
                que2.push(node2->right);
            }
            if (!node1->right) node->right = node2->right;
            if (!node1->left) node->left = node2->left;
            if (!node2->left) node->left = node1->left;
            if (!node2->right) node->right = node1->right;
        }
        return root;

    }

};