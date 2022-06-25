#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int res = 0;
        int cnt = 0;
        int i = 0; 
        while (i < s.size() && s[i] != '|') {
            if (s[i] == '*') res++;
            i++;
        }
        for (; i < s.size(); ) {
            if (s[i++] == '|') cnt++;
            int tmp = 0;
            if (cnt % 2 != 0) {
                while (i < s.size() && s[i] != '|') {
                    if (s[i++] == '*') tmp++; 
                }
                if (i >= s.size() || s[i] != '|') res += tmp;
            } else {
                while (i < s.size() && s[i] != '|') {
                    if (s[i++] == '*') res++; 
                }
            }
            
        }
        return res;
    }
};

int main() {
    Solution su;
    su.countAsterisks("l|*e*et|c**o|*de|");
    return 0;
}