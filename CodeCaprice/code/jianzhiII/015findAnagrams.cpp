#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // p中每个字符出现的次数
        unordered_map<char, int> need;
        for (auto& ch : p) need[ch]++;
        // s的窗口内，p中每个字符出现的次数
        unordered_map<char, int> win;
        // 窗口内满足need需要的字符数
        int valid = 0;
        int left = 0, right = 0;
        vector<int> res;
        while (right < s.size()) {
            char ch = s[right++];
            if (need.find(ch) != need.end()) {
                win[ch]++;
                if (win[ch] == need[ch]) valid++;  // 窗口内ch的个数满足need的需要，则该字符成为一个合法字符
            }
            while (right - left >= p.size()) {  // 排列 窗口大小应与p字符串长度相同
                if (valid == need.size()) res.push_back(left);  // 窗口内的合法字符与need中合法字符相同
                char ch = s[left++];
                if (need.find(ch) != need.end()) {
                    if (win[ch] == need[ch]) valid--;
                    win[ch]--;
                }
            }
        }
        return res;
    }
};

int main () {
    return 0;
}