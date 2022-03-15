#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];   
            maxSum = maxSum > sum ? maxSum : sum;
            if (sum <= 0) {
                sum = 0;   // 遇到和为负数的就重新开始
            } 
        }
        return maxSum;
    }
};


int main() {
    Solution su;
    vector<int> nums = {-2,-1};
    su.maxSubArray(nums);
    return 0;
}