#include<bits/stdc++.h>
using namespace std;

/* 
2261. 含最多 K 个可整除元素的子数组
给你一个整数数组 nums 和两个整数 k 和 p ，找出并返回满足要求的不同的子数组数，要求子数组中最多 k 个可被 p 整除的元素。

如果满足下述条件之一，则认为数组 nums1 和 nums2 是 不同 数组：
两数组长度 不同 ，或者 存在 至少 一个下标 i 满足 nums1[i] != nums2[i] 。
子数组 定义为：数组中的连续元素组成的一个 非空 序列。

输入：nums = [2,3,3,2,2], k = 2, p = 2
输出：11
解释：
位于下标 0、3 和 4 的元素都可以被 p = 2 整除。
共计 11 个不同子数组都满足最多含 k = 2 个可以被 2 整除的元素：
[2]、[2,3]、[2,3,3]、[2,3,3,2]、[3]、[3,3]、[3,3,2]、[3,3,2,2]、[3,2]、[3,2,2] 和 [2,2] 。
注意，尽管子数组 [2] 和 [3] 在 nums 中出现不止一次，但统计时只计数一次。
子数组 [2,3,3,2,2] 不满足条件，因为其中有 3 个元素可以被 2 整除。

 */

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> subNums;
        for (int i = 0; i < nums.size(); ++i) {
            string tmp = "";   // 包含不超过k个能被p整除的子数组的字符串
            int cnt = 0;       // 被p整除的数的个数
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] % p == 0) {
                    if (cnt == k) break;
                    cnt++;  
                } 
                tmp += to_string(nums[j]) + ",";
                subNums.insert(tmp);    // 每个符合要求的子数字串都插入set
            }
        }
        return subNums.size();
    }
};

int main() {
    vector<int> nums = {2,3,3,2,2};
    Solution su;
    int res = su.countDistinct(nums, 2, 2);
    cout << res << endl;
    return 0;
}