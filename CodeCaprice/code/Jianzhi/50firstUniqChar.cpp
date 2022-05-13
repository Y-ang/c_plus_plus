#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int hash[26] = {0};
        for (auto& ch : s) {
            hash[ch - 'a']++;
        }
        for (auto&ch : s) {
            if (hash[ch - 'a'] == 1) 
                return ch;
        }
        return ' ';
    }
};