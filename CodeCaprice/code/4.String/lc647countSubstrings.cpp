#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int countSubstrings(string s) {
//         int res = 0;
//         vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));  // dp[i][j]  i-j的串是否位回文串
//         for (int i = s.size() - 1; i >= 0; i--) {
//             for (int j = i; j < s.size(); j++) {
//                 if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {   // 字符串首尾相同，要么该字符串长度小于等于2，要么该字符串 i+1 - j-1也是回文
//                     res++;
//                     dp[i][j] = 1;
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += extend(s, i, i);
            res += extend(s, i, i+1);
        }
        return res;
    }
    int extend(string s, int left, int right) {
        int res = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            res++;
        }
        return res;
    }
};

int main() {

    return 0;
}