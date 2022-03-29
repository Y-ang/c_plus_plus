#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int res = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    if (j - i + 1 > res) res = j -i + 1;
                    dp[i][j] = 1;
                }
            }
        }
        return res;
    }
};

int main() {
    string s = "bbbab";
    Solution su;
    su.longestPalindromeSubseq(s);
    return 0;
}