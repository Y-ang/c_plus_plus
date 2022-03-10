#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        backtracking(0, 0, target, candidates, path, res);
        return res;
    }
    void backtracking(int startIndex, int sum, int target, vector<int> candidates, 
                        vector<int> path,  vector<vector<int>>& res) {
        if (sum == target) {
            res.push_back(path);
            return;
        } else if (sum > target){
            return;
        }
        // 剪枝
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // 保证每层for循环中，不会遍历到相同的数，不同for循环可能会有相同的数
            if (i != startIndex && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            backtracking(i+1, sum + candidates[i], target, candidates, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution su;
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    su.combinationSum2(nums, 8);
    return 0;
}