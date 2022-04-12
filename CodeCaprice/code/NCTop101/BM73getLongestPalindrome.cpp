#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A string字符串 
     * @return int整型
     */
    int getLongestPalindrome(string A) {
        // write code here
        // 中心扩展法
        int maxLen = 1;
        for (int i = 0; i < A.size(); i++) {
            maxLen = max({maxLen, compute(A, i, i), compute(A, i, i + 1)});
        }
        return maxLen;

        // 动规
        int maxLen = 1;
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0)); // dp[i][j] i-j串是否是回文串
        for (int i = A.size() - 1; i >= 0; --i) {
            for (int j = i; j < A.size(); ++j) {
                if (A[i] == A[j] && (j - i <= 1 || dp[i + 1][j - 1] == 1)) {
                    dp[i][j] = 1;
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;

    }
    int compute(string& str, int left, int right) {
        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

int main() {

    return 0;
}