// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string path;
        string telMap[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        backtracking(0, path, res, digits, telMap);
        return res;
    }
    void backtracking(int index, string& path, vector<string>& res, string& digits, string telMap[10]) {
        if (index >= digits.size()) {
            res.push_back(path);
            return;
        }
        string str = telMap[digits[index] - '0']; // 本层的按键的取值
        for (auto& ch : str) {
            path.push_back(ch);
            backtracking(index + 1, path, res, digits, telMap);
            path.pop_back();
        }
    }
};
// @lc code=end

