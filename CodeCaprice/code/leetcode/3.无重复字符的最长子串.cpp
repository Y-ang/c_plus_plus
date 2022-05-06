// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int maxLen = INT_MIN;
        while (right < s.size()) {
            char ch = s[right];
            right++;
            window[ch]++;
            while (window[ch] > 1) {
                window[s[left++]]--;
            }
            maxLen = max(maxLen, right - left);
        }
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};
// @lc code=end

