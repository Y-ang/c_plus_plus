#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        vector<int> used(num.size(), 0);
        sort(num.begin(), num.end());   // 排序
        backtracking({}, used, num, res);
        return res;
    }
    void backtracking(vector<int> path, vector<int>& used, vector<int>& nums, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i != 0 && used[i - 1] == 0 && nums[i - 1] == nums[i]) continue;  // 去除重复项
            used[i] = 1;
            path.push_back(nums[i]);
            backtracking(path, used, nums, res);
            path.pop_back();
            used[i] = 0;
        }
    }
};

int main() {
    Solution su;
    vector<int> nums = {1, 1, 2};
    su.permuteUnique(nums);
    return 0;
}