#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定数组的最长严格上升子序列的长度。
     * @param arr int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int>& arr) {
        // write code here
        int maxLen = 0;
        vector<int> dp(arr.size(), 1);
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) { // 比较j > i时，arr[j] 是否大于 arr[i]
                if (arr[j] > arr[i]) {
                    dp[j] = max(dp[j], dp[i] + 1);  // dp[j] > dp[i]，则子序列长度在dp[i]的基础上+1
                } 
                maxLen = max(maxLen, dp[j]);
            }
        }
        return maxLen;
    }
};

int main() {
    vector<int> nums = {1,6,4,7,5,3,2};
    Solution su;
    su.LIS(nums);

    return 0;
}