#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 方法一：二维数组 空间复杂度O(m*n)
        // 第一行、第一列的所有元素都为1
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];

        // 方法二：一维数组 空间复杂度O(n)
        // 滚动数组，因为二位数组的第一行第一列都是1，所以一维数组不断从前到后相加，结果相同
        vector<int> dp(n, 1);
        for (int j = 1; j < m; j++) { // m行
            for (int i = 1; i < n; i++) { // n列
                dp[i] += dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};


int main() {


    return 0;
}