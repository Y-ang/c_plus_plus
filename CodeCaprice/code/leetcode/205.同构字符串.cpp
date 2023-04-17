// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        // 记录字符对应的下标  一共有256个ascii
        vector<int> preIndexS(256);
        vector<int> preIndexT(256);
        for (int i = 0; i < s.size(); ++i) {
            if (preIndexS[s[i]] != preIndexT[t[i]]) return false;
            preIndexS[s[i]] = preIndexT[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end

