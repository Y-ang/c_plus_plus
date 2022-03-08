#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution
{
private:
    /* data */
public:
    void buildTree(TreeNode* node, int index, vector<int> nums) {
        if (index > nums.size() - 1) return nullptr;
    }
};




int main() {
    vector<int> nums= {1, 2, 3, 4};
    

}
