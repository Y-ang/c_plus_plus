// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
// 前缀和 + 哈希表
/* 
    满足条件的子数组： preSum[i] - preSum[j - 1] = k  (preSum[i] 表示从0-i的子数组和和)
    哈希：对于每个nums[i]寻找哈希表中是否存在值为 preSum[i] - k 的preSum, 若存在，子数组的个数增加哈希表中preSum的个数
        每次循环，哈希表都会记录到nums[i]的preSum
    初始化： 哈希表中，存在「0，1」因为前缀和为0的个数为1， 即考虑nums[i]本身为一个只为k的子数组的个数
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int preSum = 0;
        unordered_map<int, int> preSumCnt{{0, 1}};
        for (int i = 0; i < nums.size(); ++i) {
            preSum += nums[i];   // 包括当前元素的前缀和
            if (preSumCnt.find(preSum - k) != preSumCnt.end()) {  // 判断有多少个符合条件的
                res += preSumCnt[preSum - k];
            }
            preSumCnt[preSum]++; // 更新hash
        }
        return res;

    }
};
// @lc code=end

