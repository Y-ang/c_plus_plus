// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;   // nums2中有下一个最大值的元素，其元素值和下一个最大值之间的映射
        stack<int> st;   // 栈中保存的是元素值  
        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && nums2[i] > st.top()) {
                umap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            if (umap.find(nums1[i]) != umap.end()) {   // 如果umap[n]存在，则表示有下一个最大值；否则就是没有下一个最大值
                res[i] = umap[nums1[i]];
            }
        }
        return res;
    }
};
// @lc code=end

