class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> res;
        backtracing(k, n, 0, 1, path, res);
        return res;

    }
    void backtracing(int k, int n, int sum, int startIndex, vector<int> path, vector<vector<int>>& res) {
        if (sum == n && path.size() == k) {
            res.push_back(path);
            return;
        } else if (path.size() > k || sum > n){
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracing(k, n, sum+i, i+1, path, res);
            path.pop_back();
        }
    }
};