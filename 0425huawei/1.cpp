#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        backtracking(0, 0, "", s, res);
        return res;
    }
    void backtracking(int startIndex, int cnt, string path, string s, vector<string>& res) {
        if (cnt == 4) {
            path.pop_back();
            if (startIndex == s.size()) {
                res.push_back(path);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            string tmp = s.substr(startIndex, i - startIndex + 1);
            if (stoi(tmp) >= 0 && stoi(tmp) <= 255)
                backtracking(i + 1, cnt + 1, path + tmp + ".", s, res);
        }
    }
};

int main() {

    string str = "1921681312";
    Solution su;
    vector<string> res = su.restoreIpAddresses(str);
    for (auto& str : res) {
        cout << str << endl;
    }
    return 0;
}