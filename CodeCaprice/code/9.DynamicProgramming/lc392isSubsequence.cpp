#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size() && j < t.size(); i++, j++) {
            while (s[i] != t[j] && j < t.size()) {  // 向前遍历t，直到找到相同的字符
                j++;
            }
            if (s[i] == t[j]) cnt++;  // 计数，找到多少相同的字符
        }
        return cnt == s.size();
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 1; j < t.size() + 1; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};

int main() {
    string s = "axc";
    string t = "ahbgdc";
    Solution su;
    su.isSubsequence(s, t);
    return 0;
}