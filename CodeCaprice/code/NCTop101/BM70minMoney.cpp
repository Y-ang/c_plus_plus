#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int>& arr, int aim) {
        // write code here
        if (aim == 0) return 0;
        vector<int> dp(aim + 1, 5001);  // 零钱为i时，最少需要几张纸币
        dp[0] = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = arr[i]; j <= aim; ++j) {   // 完全背包，从前向后遍历
                dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
            }   
        }
        cout << dp[aim];
        return dp[aim] == 5001 ? -1 : dp[aim];
    }
};

int main() {
    vector<int> nums = {357,322,318,181,22,158,365};
    Solution su;
    su.minMoney(nums, 4976);

    return 0;
}