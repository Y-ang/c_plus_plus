#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string path;
        vector<string> res;
        backtracking(0, s, path, res, 0);
        return res;
    }

    void backtracking(int startIndex, string s, string path, vector<string>& res, int cnt) {
        
        // if (cnt >= 4 && startIndex != s.size()) {  // 剪枝 切割的分段>=4, 且没有切完到最后, 该ip就不可能合法
        //     return;
        // }
        // if (cnt == 4 && startIndex == s.size()) {  // 切割的分段为4，且切割到最后一位
        //     res.push_back(path);
        //     return;
        // }
        if (cnt == 3 && isCorrect(s.substr(startIndex, s.size() - startIndex))) {   //分到第三段且剩下的字符vaild
            res.push_back(path + '.' + s.substr(startIndex, s.size() - startIndex));
            return;
        } else if (cnt == 3){  // 分到第三段 剩下的字符不valid
            return;
        }


        for (int i = startIndex; i < startIndex + 3 && i < s.size(); i++) {
            if (!isCorrect(s.substr(startIndex, i - startIndex + 1))) continue; // 判断数值是否符合条件，以及是否有前置0
            if (startIndex != 0) path += '.';
            backtracking(i + 1, s, path + s.substr(startIndex, i - startIndex + 1), res, cnt + 1);
            if (startIndex != 0) path.pop_back();


        }
    }
    bool isCorrect(string s) {
        if (s.size() <= 0 || s.size() > 3) return false;
        int n = stoi(s);
        if (n< 0 || n > 255) {
            return false;
        }
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }
        return true;
    }
};

int main() {
    Solution su;
    string s = "25525511135";
    su.restoreIpAddresses(s);
    return 0;
}