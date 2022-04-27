#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string trans(string s, int n) {
        reverse(s.begin(), s.end());  // 反转整个字符串
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' ') {
                // 反转当前单词
                slow = fast;
                while (fast < s.size() && s[fast] != ' ') {
                    changeUpLow(s[fast]); // 改变大小写
                    fast++;
                } 
                reverse(s.begin() + slow, s.begin() + fast);
            }
        }
        return s;
    }
    
    void changeUpLow(char& ch) {
        if (ch >= 'a' && ch <= 'z') {
            ch = toupper(ch);
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = tolower(ch);
        }
    }
};

int main () {
    string str = "now        Coder ";
    Solution su;
    su.trans(str, 88888);
    return 0;
}