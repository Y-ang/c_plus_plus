// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window, need;
        for (auto& ch : p) need[ch]++;
        int left = 0, right = 0;
        int valid = 0;
        vector<int> res;
        while (right < s.size()) {
            char ch = s[right];
            right++;
            if (need.find(ch) != need.end()) {
                window[ch]++;
                if (window[ch] == need[ch]) valid++;
            }

            while (right - left >= p.size()) {
                if (valid == need.size()) res.push_back(left);
                char ch = s[left];
                left++;
                if (need.find(ch) != need.end()) {
                    if (window[ch] == need[ch]) valid--;
                    window[ch]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

