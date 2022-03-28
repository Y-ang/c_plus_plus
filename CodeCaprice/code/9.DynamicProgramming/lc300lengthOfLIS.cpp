#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); // 到位置i最长子序列的长度，初始化为1
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                } 
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {

    return 0;
}