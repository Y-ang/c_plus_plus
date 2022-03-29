#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));  // 删除操作数
        for (int i = 0; i < word1.size() + 1; i++)  dp[i][0] = i; // 初始化第一列
        for (int i = 0; i < word2.size() + 1; i++)  dp[0][i] = i; // 初始化第一行

        for (int i = 1; i < word1.size() + 1; i++) {
            for (int j = 1; j < word2.size() + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i -1][j - 1];  // 不操作
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2)); 
                    // 删除word1当前数字 操作加一; 删除word2d当前数字; 两个都删+2
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main() {
    string word1 = "a";
    string word2 = "b";
    Solution su;
    su.minDistance(word1, word2);

    return 0;
}