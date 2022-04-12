#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
        string str;

        // 计算dp数组，即最长公共子序列的长度
        for (int i = 1; i < s1.size() + 1; i++) {
            for (int j = 1; j < s2.size() + 1; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        // 从动规数组右下角向上找公共子序列
        for (int i = s1.size(), j = s2.size(); i >= 1 && j >= 1 && dp[i][j] >= 1; ) {
            if ( s1[i - 1] == s2[j - 1]) {
                str += s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(str.begin(), str.end());
        if (str == "") return "-1";
        return str;
    }
};

int main() {
    return 0;
}