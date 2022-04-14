#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        // dp[i][j] str中0 - i-1 和 pattern 0 - j-1是否匹配
        vector<vector<int>> dp(str.size() + 1, vector<int>(pattern.size() + 1));
        // s p都为空，匹配
        dp[0][0] = 1;
        // p为空，s不为空, 不匹配
        // s为空，p不为空，p中出现*则可以消灭前面一个字符为空串
        for (int i = 1; i <= pattern.size(); ++i) {
            if (pattern[i - 1] == '*') dp[0][i] = dp[0][i - 2];
        }

        // 遇到*可以匹配0-n次
        for (int i = 1; i <= str.size(); ++i) {
            for (int j = 1; j <= pattern.size(); ++j) {
                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];   // str中的字符和pattern中的字符匹配
                } else if (pattern[j - 1] == '*') { // 不匹配，但pattern中的字符为*
                    if (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') {  
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j]; // pattern中的 ''字符+*'' 用来消除str中0个字符、1个字符、大于等于两个字符
                    } else {  
                        dp[i][j] = dp[i][j - 2];  // 不匹配, 用*消掉*前面的一个字符，考察str[i - 1] 是否与 pattern[j - 3] 能匹配上
                    }
                }
            }
        }
        return dp[str.size()][pattern.size()];
    }
};

int main() {
    string str = "a";
    string pattern = ".*a";
    Solution su;
    su.match(str, pattern);
    return 0;
}