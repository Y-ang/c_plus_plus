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
    TreeNode* buildTree(int index, vector<int> nums) {
        if (index > nums.size() - 1) return nullptr;
        TreeNode* newNode = new TreeNode(nums[index]);
        newNode->left = buildTree(2 * index + 1, nums);
        newNode->right = buildTree(2 * index + 2, nums);
        return newNode;
    }
};




int main() {
    vector<int> nums= {1, 2, 3, 4};
    TreeNode* head = nullptr;
    Solution su;
    head = su.buildTree(0, nums);
    cout << 1 << endl;
    return 0;

}
