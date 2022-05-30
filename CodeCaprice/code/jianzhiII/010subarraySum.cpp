#include<bits/stdc++.h>
using namespace std;

/* 
    前缀和 + 哈希表
    preSum数组中记录到当前位置的前缀和, preSum[i]表示0-i数组元素和
    满足条件的 i - j 子数组：preSum[i] - preSum[j - 1] == k   preSum[j - 1] == preSum[i] - k
    只需要从前到后记录前缀和的哈希表, 判断到i位置有多少个子数组满足条件，就是计算哈希表中有多少个preSum[i] - k
    注：
        哈希表中本身有一项（0, 1）表示前缀和为0的有1个，即i位置0- i就满足preSum[i] == k的情况
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 本题用到前缀和和哈希表
        unordered_map<int, int> hashTab{{0, 1}};
        int res = 0;
        int pre = 0;  // 记录到i位置的前缀和, 这样可以不用修改原数组的值
        for (int i = 0; i < nums.size(); ++i) {
            pre += nums[i];
            if (hashTab.find(pre - k) != hashTab.end()) 
                res += hashTab[pre - k];  // 前缀和为pre-k的数组的个数
            hashTab[pre]++;   // 前缀和为pre的数组的个数加1
        }
        return res;
    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 本题只用到前缀和和哈希表，所以前缀和数组可以直接在nums数组上变动
        unordered_map<int, int> hashTab{{0, 1}};
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0) nums[i] += nums[i - 1];
            if (hashTab.find(nums[i] - k) != hashTab.end()) res += hashTab[nums[i] - k];  // 找到满足要求的前缀和，加上该前缀和出现的次数
            hashTab[nums[i]]++;
        }
        return res;
    }
};

int main () {
    vector<int> nums = {1, -1, 0};
    Solution su;
    su.subarraySum(nums, 0);
    return 0;
}