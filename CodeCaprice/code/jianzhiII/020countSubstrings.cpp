#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res += extend(s, i, i);
            res += extend(s, i, i + 1);
        }
        return res;
    }
    int extend(string& s, int left, int right) {
        int cnt = 0;
        while (left >= 0 && right < s.size() && s[left--] == s[right++]) {
            cnt++;
        }
        return cnt;
    }
};


int main() {
    return 0;
}