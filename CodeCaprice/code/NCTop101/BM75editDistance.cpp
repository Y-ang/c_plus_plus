#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str1 string字符串 
     * @param str2 string字符串 
     * @return int整型
     */
    int editDistance(string str1, string str2) {
        // write code here
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1)); // str1 0-i 修改为 str 0-j 的最小操作
        // 初始化当两个str中由一个为空时的编辑距离，即初始化第一行和第一列
        for (int i = 1; i <= str1.size(); ++i) dp[i][0] = i;
        for (int i = 1; i <= str2.size(); ++i) dp[0][i] = i;
        for (int i = 1; i <= str1.size(); ++i) {
            for (int j = 1; j <= str2.size(); ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1; // 在word1上置换、删除、增加一个元素
                }
            }
        }
        return dp[str1.size()][str2.size()];
    }
};

int main() {
    string str1 = "new";
    string str2 = "nowcoder";
    Solution su;
    su.editDistance(str1, str2);
    return 0;
}