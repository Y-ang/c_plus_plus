#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // t中元素的个数
        unordered_map<char, int> need;
        for (auto& ch : t) need[ch]++;
        // s窗口中的t字符的个数
        unordered_map<char, int> win;
        // 窗口中满足need要求的合法字符数
        int valid = 0;
        int left = 0, right = 0;
        int minLen = s.size() + 1;
        int startIndex = 0;
        while (right < s.size()) {
            char ch = s[right++];
            if (need.find(ch) != need.end()) {  
                win[ch]++;
                if (win[ch] == need[ch]) valid++; // 该元素在窗口内的个数满足need的要求
            }
            while (valid == need.size()) {  // 窗口内覆盖了need中的所有元素
                if (right - left < minLen) {
                    minLen = right - left;
                    startIndex = left;
                }
                char ch = s[left++];
                if (need.find(ch) != need.end()) {
                    if (win[ch] == need[ch]) valid--;  // 所有做窗口，更新valid
                    win[ch]--;
                }
            }
        }
        return minLen == s.size() + 1 ? "" : s.substr(startIndex, minLen);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution su;
    su.minWindow(s, t);
    return 0;
}