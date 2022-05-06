// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 记录字符出现的次数
        unordered_map<char, int> window, need;
        for (auto& ch : s1) need[ch]++;
        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            // 扩大右窗口
            char ch = s2[right];
            right++;
            if (need.find(ch) != need.end()) {   // 找到字符，更新窗口内字符出现的次数
                window[ch]++;
                if (window[ch] == need[ch]) valid++;
            }
            // 这道题子串中不能含有s1以外的字符，所以s2的子串长度应与s1相同
            while (right - left >= s1.size()) {
                if (valid == need.size()) return true;
                char ch = s2[left];
                left++;
                if (need.find(ch) != need.end()) {   // 删掉字符，减少窗口内字符出现的次数
                    if (window[ch] == need[ch]) valid--;
                    window[ch]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    string str1 = "abcdxabcde";
    string str2 = "abcdeabcdx";
    Solution su;
    su.checkInclusion(str1, str2);
    return 0;
}