class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        backtracking(0, nums, path, res);
        return res;
    }
    void backtracking(int startIndex, vector<int> nums, vector<int> path, vector<vector<int>>& res) {
        if (startIndex > nums.size() - 1) {
            return;
        }
        // unordered_set<int> elem; //只控制本层的去重
        int elem[201] = {0};  //用数组更省时
        for (int i = startIndex; i < nums.size(); i++) {
            // if (elem.find(nums[i]) != elem.end() || (!path.empty() && path[path.size() - 1] > nums[i])) {
            //     continue;
            // }  // 有重复或者不递增就直接跳过
            // elem.insert(nums[i]);
            if (elem[nums[i] + 100] == 1 || (!path.empty() && path.back() > nums[i])) {
                continue;
            }
            elem[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            if(path.size() > 1) res.push_back(path); //只保存元素个数大于2的数组
            backtracking(i + 1, nums, path, res);
            path.pop_back();
        }
    }
};