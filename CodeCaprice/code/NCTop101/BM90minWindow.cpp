class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    string minWindow(string S, string T) {
        unordered_map<char, int> window, need;
        for (auto& ch : T) need[ch]++;
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, minLen = INT_MAX;
        while (right < S.size()) {
            char ch = S[right++];  // 左闭右开区间，扩大右边窗口值
            if (need.find(ch) != need.end()) {
                window[ch]++;
                if (window[ch] == need[ch]) valid++;
            }
            // 找到可行解，逐步确定最优解
            while (valid == need.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char ch = S[left++];  // 收缩左窗口
                if (need.find(ch) != need.end()) {
                    if (window[ch] == need[ch]) valid--;
                    window[ch]--;
                }
            }
        }
        return minLen == INT_MAX ? "" : S.substr(start, minLen);
    }
};