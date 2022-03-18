#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);  // 排序， 按照左坐标递增排序
        vector<vector<int>> res;
        int left = intervals[0][0];   // 初始区间
        int right = intervals[0][1];
        for (auto& interval : intervals) {
            if (right < interval[0]) {  // 区间不重叠， 保存前一个区间，更新新的区间
                res.push_back(vector<int>{left, right});
                left = interval[0];
                right = interval[1];
            } else {
                right = max(right, interval[1]);   // 区间有重合时，更新最大坐标
            }
        }
        res.push_back(vector<int>{left, right});
        return res;
    }
};

int main() {
    // vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> nums = {{1,4},{4,5}};
    Solution su;
    su.merge(nums);
    return 0;
}