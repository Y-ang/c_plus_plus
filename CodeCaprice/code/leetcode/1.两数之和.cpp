// @before-stub-for-debug-begin
#include<bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;   // 值和下标之间的映射
        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(target - nums[i]) != umap.end()) {
                return {umap[target- nums[i]], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

