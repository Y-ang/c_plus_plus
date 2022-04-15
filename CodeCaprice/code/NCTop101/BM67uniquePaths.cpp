#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param m int整型 
     * @param n int整型 
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        // write code here
        vector<int> dp(n, 1);
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                dp[i] += dp[i - 1];
            }
        }
        
        return dp[n - 1];

        // vector<vector<int>> dp(m, vector<int>(n));
        // for (int i = 0; i < m; i++) dp[i][0] = 1;
        // for (int i = 0; i < n; i++) dp[0][i] = 1;
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //     }
        // }
        // return dp[m - 1][n - 1];
    }
};
