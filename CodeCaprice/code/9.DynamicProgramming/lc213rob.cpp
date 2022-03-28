# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        // 既然是环，打破环编程两个序列就行了，因为首尾两个元素只有一个能被取到
        // 只考虑首元素，不考虑尾元素 以及只考虑尾元素，不考虑首元素
        int res = max(robDp(vector<int>(nums.begin(), nums.begin() + nums.size() - 1)), robDp(vector<int>(nums.begin() + 1, nums.end())));
        return res;
    }
    int robDp(vector<int> nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};


int main() {

    return 0;
}