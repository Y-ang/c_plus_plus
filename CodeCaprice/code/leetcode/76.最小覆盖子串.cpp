// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 记录窗口内的字符计数和t中的字符计数
        unordered_map<char, int> window, need;
        for (auto& ch : t) need[ch]++;
        int left =0, right = 0;
        int valid = 0;  // 窗口内满足要求的字符的个数
        int start = 0, minLen = INT_MAX; // 满足要求的子串的开始下标和长度
        while (right < s.size()) {
            // 扩大右边窗口，找到可行解
            char ch = s[right];
            right++;
            if (need.find(ch) != need.end()) {
                window[ch]++;
                if (window[ch] == need[ch]) valid++;
            }

            // 找到可行解(window中满足要求的字符数量等于need中的字符数量)，缩小左边窗口，以找到最优解
            while (valid == need.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                // 缩小左窗口
                char ch = s[left];
                left++;
                if (need.find(ch) != need.end()) {
                    if (window[ch] == need[ch]) valid--;
                    window[ch]--;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
// @lc code=end

