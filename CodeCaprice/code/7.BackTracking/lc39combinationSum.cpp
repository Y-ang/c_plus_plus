class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if (target < candidates[0]) return {};
        vector<int> path;
        vector<vector<int>> res;
        backtracking(0, candidates, 0, target, path, res);
        return res;
    }

    void backtracking(int stratIndex, vector<int> candidates, int sum, int target, 
                        vector<int> path, vector<vector<int>>& res) {
        if (sum == target) {
            res.push_back(path);
            return;
        } else if (sum > target || stratIndex > candidates.size() - 1) {
            return;
        }
        // 剪枝 sum + candidates[i] <= target，因为如果当前sum>target,就不需要进入下一层循环
        for (int i = stratIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            path.push_back(candidates[i]);
            backtracking(i, candidates, sum + candidates[i], target, path, res);
            path.pop_back();
        }
    }
};