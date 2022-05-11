// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
// 回溯
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return backtracking(0, memo, s, wordSet);
    }

    bool backtracking(int startIndex, vector<int>& memo, string& s, unordered_set<string>& wordSet) {
        if (startIndex == s.size()) {
            return true;
        }
        if (memo[startIndex] != -1) return memo[startIndex];
        for (int i = startIndex; i < s.size(); ++i) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(i + 1, memo, s, wordSet)) {
                memo[startIndex] = 1;
                return true;
            }
        }
        memo[startIndex] = 0;
        return false;
    }

};
// @lc code=end

// 动规
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // s长度是背包的大小，s分割的字符串就是物品，要看物品在不在wordDict内并且能不能装满背包
        // dp[i] 取决于 dp[j] & dp[j + 1 ... i]     dp[j] --> s[0 - j-1]
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i) {   // 背包    计算第dp[i]能不能拆分成字典中的单词    
            for (int j = 0; j < i; ++j) {      // 截取的word
                string word = s.substr(j, i - j);
                if (dp[j] && wordSet.find(word) != wordSet.end()) dp[i] = 1; //dp[j] 0-j-1 在字典中，看j - i - 1是不是在字典中
            }
        }
        return dp[s.size()];
    }
};
