class Solution {

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        int sum = 0;
        for (int i = 0; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i !=0 && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            backtracking(i + 1, sum + candidates[i], target, candidates, path, res);
            path.pop_back();
        }
        
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
            path.push_back(candidates[i]);
            backtracking(i+1, sum + candidates[i], target, candidates, path, res);
            path.pop_back();
        }
    }
};