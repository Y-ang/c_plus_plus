// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
// 前缀和 时间复杂度O(1)
class NumArray {
public:
    NumArray(vector<int>& nums) {
        preSum.resize(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) preSum[i] = preSum[i - 1] + nums[i - 1];  // preSum[i]中保存nums 0 - i-1中的元素和
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
private:
    vector<int> preSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
// 直接索引返回 时间复杂度O(n)
class NumArray {
public:
    NumArray(vector<int>& nums) {
        arr.reserve(nums.size());
        for (auto& n : nums) arr.push_back(n);
    }
    
    int sumRange(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; ++i) {
            res += arr[i];
        }
        return res;
    }
private:
    vector<int> arr;
};