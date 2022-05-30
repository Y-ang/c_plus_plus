#include <bits/stdc++.h>
using namespace std;

// i左右侧元素相等即为 2 * preSum + nums[i] == total 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (auto& n : nums) total += n; 
        int preSum = 0; // 记录前缀和
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * preSum + nums[i] == total) return i;
            preSum += nums[i];
        }
        return -1;
    }
};


// 保存前缀和数组，空间复杂度为O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 前缀和问题
        vector<int> preSum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            preSum[i + 1] = preSum[i] + nums[i]; // i + 1的前缀和 = i的前缀和 + nums[i]
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (preSum[i] == preSum[nums.size()] - preSum[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution su;
    vector<int> nums = {1,7,3,6,5,6};
    su.pivotIndex(nums);
    return 0;
}