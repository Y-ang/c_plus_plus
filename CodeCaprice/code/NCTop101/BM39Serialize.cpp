#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val_) : val(val_), left(nullptr), right(nullptr) {}
};

// 前序遍历
class Solution {
public:
    char* Serialize(TreeNode *root) {
        if (root == nullptr) return nullptr;
        string res;
        traverse(root, res);
        res.pop_back(); // 弹出末尾的，号
        char* ans = new char[res.size() + 1];
        strcpy(ans, res.c_str());
        return ans;
    }

    TreeNode* Deserialize(char *str) {
        if(str == nullptr) return nullptr;
        // 分割节点
        queue<string> nodeVal;
        split(str, nodeVal, ',');

        return deserialize(nodeVal);
    }

    void traverse(TreeNode* root, string& res) {
        if (root == nullptr) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ","; // 已以逗号分割
        traverse(root->left, res);
        traverse(root->right, res);
    }

    void split(string str, queue<string>& nodeVal, char c) {
        stringstream ss(str);
        string tmp;
        while (getline(ss, tmp, c)) nodeVal.push(tmp);
        if (str.size() > 0 && str.back() == c) nodeVal.push("");   // 最后元素为分隔符
    }

    TreeNode* deserialize(queue<string>& nodeVal) {
        if (nodeVal.empty()) return nullptr;
        if (nodeVal.front() == "#") {
            nodeVal.pop();
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(nodeVal.front()));   // 用先序遍历方法构建先序遍历序列，只需要从前到后即可
        nodeVal.pop();
        root->left = deserialize(nodeVal);
        root->right = deserialize(nodeVal);
        return root;
    }
};



/* // 层序遍历
class Solution {
public:
    char* Serialize(TreeNode *root) {
        if (root == nullptr) return nullptr;
        queue<TreeNode*> que;
        string res;
        if (root) que.push(root);
        while (!que.empty()) {
            TreeNode* cur =que.front();
            que.pop();
            if (cur == nullptr) {   // 为空
                res += "#,";
            } else {                // 不为空
                res += to_string(cur->val) + ",";
                que.push(cur->left);
                que.push(cur->right);
            }
        }
        res.pop_back(); // 将最后的','去掉
        char* ans = new char[res.size() + 1];
        strcpy(ans, res.c_str());
        return ans;
    }
    TreeNode* Deserialize(char *str) {
        if (str == nullptr) return nullptr;
        TreeNode* root = nullptr;
        string s = str;
        queue<string> nodeVal;  // 节点的值
        split(s, nodeVal, ',');

        queue<TreeNode*> visited;    // 记录已经访问的节点，从已经访问的节点中逐步弹出头节点
        if (!nodeVal.empty()) {
            root = new TreeNode(stoi(nodeVal.front()));
            nodeVal.pop();
            visited.push(root);
        }

        while (!nodeVal.empty()) {    // nodeVal中队顶元素为子节点，访问后加入visited队列；从visited队列不断弹出元素作为队顶元素
            TreeNode* cur = visited.front();
            visited.pop();
            if (cur == nullptr) continue;
            cur->left = nodeVal.front() == "#" ? nullptr : new TreeNode(stoi(nodeVal.front()));
            nodeVal.pop();
            visited.push(cur->left);
            cur->right = nodeVal.front() == "#" ? nullptr : new TreeNode(stoi(nodeVal.front()));
            nodeVal.pop();
            visited.push(cur->right);
        }
            
        return root;
    }

    void split(string& s, queue<string>& seq, char c) {
        stringstream ss(s);
        string tmp;
        while (getline(ss, tmp, c)) seq.push(tmp);
        if (s.size() > 0 && s.back() == c) seq.push("");   // 最后一个分隔符后没有元素
    }
}; */


int main() {
    string str = "1,2,3,#,#,6,7";
    Solution su;
    TreeNode* root = su.Deserialize((char*)str.c_str());
    char* s = su.Serialize(root);
    printf("%s", s);
    return 0;
}