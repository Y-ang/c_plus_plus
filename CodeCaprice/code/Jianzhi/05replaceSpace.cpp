#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int spaceNum = 0;
        for (auto& ch : s) {
            if (ch == ' ') spaceNum++;
        }
        int oldSize = s.size();
        int newSize = oldSize + spaceNum * 2;
        s.resize(newSize);
        while (oldSize > 0) {
            if (s[oldSize - 1] == ' ') {
                s[--newSize] = '0';
                s[--newSize] = '2';
                s[--newSize] = '\%';
                oldSize--;
            } else {
                s[--newSize] = s[--oldSize];
            }
        }
        return s;
    }
};

int main() {
    string str = "we are happy";
    Solution su;
    su.replaceSpace(str);
    return 0;
}