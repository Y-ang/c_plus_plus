#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     static bool cmp(vector<int> a, vector<int> b) {
//         return a[0] < b[0];
//     }
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         // 按照坐标递增的顺序排序
//         sort(points.begin(), points.end(), cmp);
//         int preIndex = points[0][1]; //前一个箭的位置
//         int cnt = 0;
//         for (int i = 0; i < points.size(); i++) {
//             if (preIndex < points[i][0]) {
//                 cnt++;   // 前一个箭不能射过当前气球
//                 preIndex = points[i][1];
//             } else if (preIndex > points[i][1]) {  // 箭超过了最大值
//                 preIndex = points[i][1];
//             }
//         }
//         cnt++;
//         return cnt;
//     }
// };

class Solution {
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 按照坐标递增的顺序排序
        sort(points.begin(), points.end(), cmp);
        // int preIndex = points[0][1]; //前一个箭的位置
        int cnt = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i] < points[i + 1][0]) {
                cnt++;   // 前一个箭不能射过当前气球
                preIndex = points[i][1];
            } else if (preIndex > points[i][1]) {  // 箭超过了最大值
                preIndex = points[i][1];
            }
        }
        cnt++;
        return cnt;
    }
};

int main () {
    vector<vector<int>> nums = {{0,0},{0,0},{0,0},{0,0}};
    Solution su;
    su.findMinArrowShots(nums);
    return 0;
}