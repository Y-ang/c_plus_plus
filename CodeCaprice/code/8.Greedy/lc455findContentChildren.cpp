#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int max = 0;
        if (s.size() == 0 || g.size() == 0) return max;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        if (s[s.size() - 1] < g[0]) return max;
        for (int i = s.size() - 1, j = g.size() - 1; i >= 0 && j >= 0; j--) { //大的饼干优先喂给食量大的孩子 或者小饼干先喂给食量小的孩子
            if (s[i] >= g[j]) {
                i--;
                max++;
            }
        }
        return max;
    }
};