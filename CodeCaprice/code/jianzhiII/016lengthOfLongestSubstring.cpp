#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 窗口内字符出现的次数
        unordered_map<char, int> win;
        int res = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            char ch = s[right++];
            win[ch]++;   // 右窗口字符出现的次数
            while (win[ch] > 1) { // 保证窗口内每个字符只出现一次
                win[s[left++]]--;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

int main() {
    return 0;
}