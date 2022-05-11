// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;  // 保存一个单调递减的堆
        for (int i = 0; i < nums.size() * 2; ++i) {    // 因为是循环数组，所以遍历两边数组
            int index = i % nums.size();  
            while (!st.empty() && nums[index] > nums[st.top()]) {
                res[st.top()] = nums[index];
                st.pop();
            }
            st.push(index);
        }
        return res;
    }
};
// @lc code=end

