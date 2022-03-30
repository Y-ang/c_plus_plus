#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int startIndex = 0;
//         int endIndex = 0;
//         vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
//         for (int i = s.size() - 1; i >= 0; i--) {

//             for (int j = i; j < s.size(); j++) {
//                 if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
//                     dp[i][j] = 1;
//                     if (j - i >= endIndex - startIndex) {
//                         startIndex = i;
//                         endIndex = j;
//                     }
//                 }
//             }
//         } 
//         string res(s.begin() + startIndex, s.begin() + endIndex + 1);
//         // cout << res;
//         return res;
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        int startIndex = 0;
        int endIndex = 0;

        for (int i = 0; i < s.size(); i++) {
            int len1 = extend(s, i, i);
            int len2 = extend(s, i, i + 1);
            int maxLen = max(len1, len2);
            if (maxLen > endIndex - startIndex + 1) {   // 统一奇数长度和偶数长度回文串的求解
                startIndex = i - (maxLen - 1) / 2;   
                endIndex = i + maxLen / 2;
            }
    
        }
        string res(s.begin() + startIndex, s.begin() + endIndex + 1);
        return res;
    }
    int extend(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // right left中间部分是回文字串，不包括left和right
        // (right - 1) - (left + 1) + 1
        return right - left - 1;
    }
};



int main() {
    string s = "babad";
    Solution su;
    su.longestPalindrome(s);

    return 0;
}