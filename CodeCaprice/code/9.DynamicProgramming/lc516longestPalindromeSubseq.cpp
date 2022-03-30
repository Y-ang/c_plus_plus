#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0)); // i-j字符串中最长回文子序列的长度
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1]; // 计算归到右上角
    }
};

int main() {
    string s = "bbbab";
    Solution su;
    su.longestPalindromeSubseq(s);
    return 0;
}