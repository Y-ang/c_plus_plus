#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 0;
        int preMax = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < preMax) {
                cnt++;
                continue;
            }
            
        }
    }
};

int main() {


    return 0;
}