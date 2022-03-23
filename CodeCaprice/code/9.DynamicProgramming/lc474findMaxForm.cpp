#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[i][j]表示有0-i个0, 0-j个1时 子集的最大长度
        for (int i = 0; i < strs.size(); i++) {
            int len0 = count(strs[i].begin(), strs[i].end(), '0');
            int len1 = strs[i].size() - len0;
            for (int row = m; row >= len0; row--) {  // 从后向前遍历背包
                for (int col = n; col >= len1; col--) {
                    dp[row][col] = max(dp[row][col], dp[row - len0][col - len1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};


int main() {
    vector<string> nums = {"10","0001","111001","1","0"};
    Solution su;
    su.findMaxForm(nums, 5, 3);

    return 0;
}