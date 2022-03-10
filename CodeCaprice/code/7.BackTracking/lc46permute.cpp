#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        int used[21] = {0};
        backtracking(used, nums, 0, path, res);
        return res;
    }
    void backtracking(int used[], vector<int> nums, int depth, vector<int> path, vector<vector<int>>& res) {
        if (depth == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[nums[i] + 10] == 1) continue;
            used[nums[i] + 10] = 1;
            path.push_back(nums[i]);
            backtracking(used, nums, depth+1, path, res);
            used[nums[i] + 10] = 0;
            path.pop_back();
        }
    }
    void output(int nums[]) {
        for (int i = 0; i < 21; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution su;
    vector<int> nums = {1, 2, 3};
    su.permute(nums);
    return 0;
}