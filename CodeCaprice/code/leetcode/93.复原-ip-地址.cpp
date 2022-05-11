// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        backtracking(0, 0, path, res, s);
        return res;
    }
    void backtracking(int startIndex, int cnt,  string path, vector<string>& res, string& s) {
        if (startIndex >= s.size() || cnt >= 4) {      // 切割完 或者 已经分割为4段
            if (cnt == 4 && startIndex == s.size()) {
                path.pop_back(); // 把最后一个'.'删掉
                res.push_back(path);
            }
            return;
        }
        
        for (int i = startIndex; i < s.size(); ++i) {
            string tmp = s.substr(startIndex, i - startIndex + 1);  // 切割startIndex到i的字符串
            if (isValid(tmp)) {
                backtracking(i + 1, cnt + 1, path + tmp + ".", res, s);
            }
        }
    }

    bool isValid(string& str) {
        if (str.size() > 3 || str.size() <= 0) return false;  // 超出长度
        if (str.size() > 1 && str[0] == '0') return false; // 前导零
        if (stoi(str) < 0 || stoi(str) > 255) return false;
        return true;
    }
};
// @lc code=end


// int main() {
//     string str = "25525511135";
//     Solution su;
//     vector<string> res = su.restoreIpAddresses(str);
//     for (auto& str : res) {
//         cout << str << endl;
//     }
//     return 0;
// }
