#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        dp[0][0] = matrix[0][0];
        for (int i = 1; i < matrix.size(); i++) dp[i][0] = matrix[i][0] + dp[i - 1][0];
        for (int i = 1; i < matrix[0].size(); ++i) dp[0][i] = matrix[0][i] + dp[0][i - 1];
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[matrix.size() - 1][matrix[0].size() - 1];
    }
};

int main () {
    Solution su;
    vector<vector<int>> nums = {{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
    su.minPathSum(nums);
    return 0;
}