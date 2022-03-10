#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // 排序后才能按照nums顺序去除同一层上重复的元素
        vector<bool> used(nums.size(), false);
        backtracking(used, nums, path, res);
        return res;
    }
    void backtracking(vector<bool> used, vector<int> nums, vector<int> path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        // int repeat[21] = {0};
        for (int i = 0; i < nums.size(); i++) {
            // if (used[i] == true || repeat[nums[i] + 10] == 1) {
            //     continue;
            // }
            // repeat[nums[i] + 10] = 1;
            // 当前数在上一层循环中被用过则不能再用 || 当前数与同一层的前一个数重复，也不能被用
            if (used[i] == true || (i != 0 && nums[i] == nums[i-1] && used[i - 1] == false)) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(used, nums, path, res);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution su;
    vector<int> nums = {1, 1, 2};
    su.permuteUnique(nums);
    return 0;
}