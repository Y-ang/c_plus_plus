#include<bits/stdc++.h>
using namespace std;

// 贪心
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;
        int tmp = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                res = max(res, tmp);
                tmp = 0;
            }
            tmp++;
        }
        res = max(res, tmp);
        return res;
    }
};
// 动规
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } 
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main () {
    vector<int> nums = {1, 2,3,4};
    Solution su;
    su.findLengthOfLCIS(nums);

    return 0;
}