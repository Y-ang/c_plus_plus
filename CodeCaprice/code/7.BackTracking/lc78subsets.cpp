#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { 
        vector<int> path;
        vector<vector<int>> res = {{}};
        backtracking(0, nums, path, res);
        return res;
    }
    void backtracking(int startIndex, vector<int> nums, vector<int> path, vector<vector<int>>& res) {
        if (startIndex > nums.size() - 1) {  // 超过结合元素的取值范围，终止
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            res.push_back(path);   // 每个组合都是符合条件的集合，直接加入res，不需要判断
            backtracking(i + 1, nums, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution su;
    vector<int> nums = {1, 2, 3};
    su.subsets(nums);
    return 0;
}