class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 记录窗口内字符出现的次数
        unordered_map<char, int> unmap;
        int res = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            unmap[s[right]]++;
            while (unmap[s[right]] > 1) {
                unmap[s[left++]]--;
            }
            res = max(res, right - left + 1);
        } 
        return res;
    }
};