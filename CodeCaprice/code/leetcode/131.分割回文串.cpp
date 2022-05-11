// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtracking(0, path, res, s);
        return res;
    }
    void backtracking(int startIndex, vector<string>& path, vector<vector<string>>& res, string& s) {
        if (startIndex == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            string tmp = s.substr(startIndex, i - startIndex + 1);   // 截取startIndex到i的字符串
            if (isPalindrome(tmp)) {
                path.push_back(tmp);
                backtracking(i + 1, path, res, s);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string& str) {
        for (int left = 0, right = str.size() - 1; left < right; left++, right--) {
            if (str[left] != str[right]) return false;
        }
        return true;
    }
};
// @lc code=end

