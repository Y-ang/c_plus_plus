class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        vector<int> vis(26); // 记录字母有没有被访问过
        vector<int> freq(26); // 记录每个字母出现的次数
        for (auto& ch : s) {
            freq[ch - 'a']++;
        }
        for (auto& ch : s) {
            if (vis[ch - 'a']) {
                freq[ch - 'a']--;
                continue;       // 该字母已经入栈，遍历过出现次数就减一
            }
            while (!res.empty() && res.back() > ch && freq[res.back() - 'a'] > 0) {  // 栈尾字典序较大，且后面还会出现该元素
                vis[res.back() - 'a'] = 0;   // 元素出栈
                res.pop_back();
            }
            res.push_back(ch);   // 入栈当前元素
            freq[ch - 'a']--;
            vis[ch - 'a'] = 1;
        }
        return res;
    }
};