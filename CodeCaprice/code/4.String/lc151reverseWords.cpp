#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        while(s[0] == ' ') {
            s.erase(0, 1);
        }
        while(s[s.size() - 1] == ' ') {
            s.erase(s.size() - 1);
        }
        for (int i = 0; i < s.size(); i++) {
            while (i != 0 && s[i] == ' ' && s[i - 1] == ' ') {
                s.erase(i, 1);
            }
        }

        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            while (i < s.size() - 1 && s[i] != ' ' ) i++;
            i = i == s.size() - 1 ? s.size() : i;
            reverse(s.begin() + left, s.begin() + i);
        }

        return s;
    }
};

int main() {
    Solution su;
    su.reverseWords("the sky is blue");
    return 0;
}