#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        backtracking(0, 0, "", s, res);
        return res;
    }

    void backtracking(int startIndex, int cnt, string str, string& s, vector<string>& res) {
        if (cnt == 4 && startIndex >= s.size()) {  // 分割成四段且字符串全部被分割完
            str.pop_back();//将最后一个'.'弹出
            res.push_back(str);
            return;
        } else if (cnt >= 4) {
            return;
        }
        for (int i = 1; i <= 3 && startIndex + i <= s.size(); ++i) {  // 从startIndex向后分割1-3个长度的子串
            string tmp = s.substr(startIndex, i);
            if (s[startIndex] == '0') {
                backtracking(startIndex + 1, cnt + 1, str + "0.", s, res);
                return;
            }
            else if (stoi(tmp) < 256){
                backtracking(startIndex + i, cnt + 1, str + tmp + ".",s, res);
            }  
        }
    }
};

int main() {
    Solution su;
    string str = "25525522135";
    su.restoreIpAddresses(str);
    return 0;
}