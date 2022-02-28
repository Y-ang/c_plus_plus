/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        // //递归
        // if (root == nullptr) return 0;
        // int depth = 0;
        // for (int i = 0; i < root->children.size(); i++) {
        //     depth = max(maxDepth(root->children[i]),depth);
        // }
        // return 1 + depth;

        // 迭代
        queue<Node*> que;
        int depth = 0;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                Node* cur = que.front();
                que.pop();
                for (int j = 0; j < cur->children.size(); j++) {
                    if (cur->children[j]) que.push(cur->children[j]);
                }
            }
        } 
        return depth;
    }
};