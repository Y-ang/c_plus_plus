#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 记录s1中字符出现的次数
        unordered_map<char, int> need;
        for (auto& ch : s1) need[ch]++;
        // 记录s2的窗口内s1中字符出现的次数
        unordered_map<char, int> win;
        // 窗口内满足need要求的字符个数
        int valid = 0;
        // 滑动的窗口
        int left = 0, right = 0;
        while (right < s2.size()) {
            char ch = s2[right++]; // 扩大窗口
            if (need.find(ch) != need.end()) {  // 右窗内的字符在s1中
                win[ch]++;
                if (win[ch] == need[ch]) valid++;  // ch字符在win中的数量满足了need的需要，更新valid表示有一个字符已经满足要求
            }
            while (right - left >= s1.size()) { // 求排列 窗口的大小只能是s1的大小
                if (valid == need.size()) {  // 窗口内满足要求的字符数等于need需要的字符数
                    return true;
                }
                char ch = s2[left++];
                if (need.find(ch) != need.end()) {
                    if (win[ch] == need[ch]) valid--;
                    win[ch]--;
                }
            }
        }
        return false;
    }
};

int main() {
    string s1 = "hello";
    string s2 = "ooolleoooleh";
    Solution su;
    su.checkInclusion(s1, s2);
    return 0;
}