#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
        int maxLen = 0;
        int pos = 0;

        // 计算dp，最长连续公共字串的长度
        for (int i = 1; i <= str1.size(); ++i) {
            for (int j = 1; j <= str2.size(); ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    pos = i - 1;
                }
            }
        }
        
        return str1.substr(pos - maxLen + 1, maxLen);
    }
};

int main() {

    return 0;
}