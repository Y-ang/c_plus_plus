#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int numSquares(int n) {
//         // 求小于n的完全完全平方数
//         vector<int> nums;
//         for (int i = 1; i <= floor(sqrt(n)); i++) {
//             nums.push_back(i * i);
//         }
//         // 动规
//         vector<int> dp(n + 1, INT_MAX); // dp[j] 表示和为j的平方数的数量
//         dp[0] = 0;   // 求数量和，首元素初始化为0
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = nums[i]; j <= n; j++) {
//                 if (j - nums[i] == INT_MAX) continue;
//                 dp[j] = min(dp[j], dp[j - nums[i]] + 1);
//             }
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int numSquares(int n) {

        // 动规
        vector<int> dp(n + 1, INT_MAX); // dp[j] 表示和为j的平方数的数量
        dp[0] = 0;   // 求数量和，首元素初始化为0
        for (int i = 1; i * i <= n; i++) {   // 遍历到n的完全平方数
            for (int j = i * i; j <= n; j++) {   
                if (j - i * i == INT_MAX) continue;
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution su;
    su.numSquares(13);

    return 0;
}