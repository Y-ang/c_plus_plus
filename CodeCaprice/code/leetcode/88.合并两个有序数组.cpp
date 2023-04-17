// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int end = m + n - 1;
        int end1 = m - 1;
        int end2 = n - 1;
        while (end1 >= 0 && end2 >= 0) {
            if (nums1[end1] > nums2[end2]) {
                nums1[end--] = nums1[end1--];
            } else {
                nums1[end--] = nums2[end2--];
            }
        }
        // nums2中还剩余元素
        while (end2 >= 0) {
            nums1[end--] = nums2[end2--];
        }

    }
};
// @lc code=end

