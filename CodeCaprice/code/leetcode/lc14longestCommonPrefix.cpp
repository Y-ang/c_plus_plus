#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            res = maxPrefix(res, strs[i]);
        }
        return res;
    }
    string maxPrefix(string& str1, string& str2) {
        int index = 0;
        while (index < str1.size() && index < str2.size()) {
            if (str1[index] != str2[index]) {
                break;
            }
            index++;
        }
        if (index == str1.size()) return str1;
        else if (index == str2.size()) return str2;
        return str1.substr(0, index);
    }
};

int main() {
    vector<string> strs = {"flower","flow","flight"};
    Solution su;
    su.longestCommonPrefix(strs);
    return 0;
}