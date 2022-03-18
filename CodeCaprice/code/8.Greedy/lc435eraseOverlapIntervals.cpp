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
            if (intervals[i][0] < preMax) { // 有重叠
                cnt++;
                preMax = min(preMax, intervals[i][1]); // 删掉范围大的，保留范围小的
            } else {
                preMax = intervals[i][1];    // 无重叠，更新最大范围为当前点的右坐标
            }
        }
        return cnt;
    }
};

int main() {
    Solution su;
    vector<vector<int>> nums = {{0,2},{1,3},{2,4},{3,5},{4,6}};
    su.eraseOverlapIntervals(nums);
    return 0;
}