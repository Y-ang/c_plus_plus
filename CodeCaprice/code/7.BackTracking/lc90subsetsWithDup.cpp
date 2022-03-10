#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        backtracking(0, nums, path, res);
        return res;
    }
    void backtracking(int startIndex, vector<int> nums, vector<int> path, vector<vector<int>>& res) {
        if (startIndex > nums.size() - 1) return;

        for (int i = startIndex; i < nums.size(); i++) {
            if (i != startIndex && nums[i] == nums[i - 1]) { //每层for循环除第一个元素，不会出现重复元素
                continue;
            }
            path.push_back(nums[i]);
            res.push_back(path);
            backtracking(i + 1, nums, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution su;
    vector<int> nums = {1, 2, 2};
    su.subsetsWithDup(nums);
    return 0;
}