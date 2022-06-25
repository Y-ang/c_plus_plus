#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp (vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), cmp);
        
    }
};