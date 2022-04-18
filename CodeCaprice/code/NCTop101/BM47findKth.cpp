#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp (const int a, const int b) {
        return a > b;
    }
    int findKth(vector<int> a, int n, int K) {
        sort(a.begin(), a.end(), cmp);
        return a[K];
    }
};

int main () {
    Solution su;
    vector<int> a = {13,11,5,6,12,13,5};
    su.findKth(a, 7, 4);
    return 0;
}