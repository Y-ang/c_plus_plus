// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// 二分查找，类似于纸牌游戏，从前到后遍历纸牌，将纸牌分堆：纸牌只能放到比它大的纸牌上；如果没有地方可以放，则新建堆
// 纸牌堆的数量就是最长子序列的长度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 记录每堆数最上面的一个纸牌的值，即每堆的最小值（后面待分堆的元素需要判断当前已存在的堆顶值是否比它大）
        vector<int> piles = {nums[0]};
        for (auto& n : nums) {
            // 二分查找满足可以安放当前n的堆  堆顶牌是按照从小到大的有序排列
            // 找到第一个大于n的数
            int left = 0, right = piles.size();  // 左闭右开区间，right取值为区间长度
            while (left < right) {
                int mid = left + ((right - left) >> 1);
                if (piles[mid] >= n) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            // 二分找到堆中的位置则更新堆顶，若没有找到则新添入这个元素
            if (left == piles.size()) piles.push_back(n); // 没有找到，则新建一个堆（现在存在的堆顶元素都比n小,在二分查找的过程中left不断右移）
            else piles[left] = n;  // 找到可以放n的堆，更新堆顶为当前的最小值
        }
        return piles.size();
    }
};
// @lc code=end

// // 动规，dp[i]表示到下标i，最长递增子序列的长度为dp[i]. 对于数组中的每个数，在它前面比他小的dp[j]上长度加1
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> dp(nums.size(), 1);
//         int res = 1;
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = 0; j < i; ++j) {  // i前面比num[i]小的数
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//                 res = max(res, dp[i]);
//             }
//         }
//         return res;
//     }
// };
