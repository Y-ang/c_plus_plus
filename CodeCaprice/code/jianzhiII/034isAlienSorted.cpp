#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int hash[26] = {0};
        int pos = 0;   // 位置
        for (auto& letter : order) {
            hash[letter - 'a'] = ++pos;
        }
    } 
};