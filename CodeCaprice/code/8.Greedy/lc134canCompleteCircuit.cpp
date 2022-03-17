#include<bits/stdc++.h>
using namespace std;


// // 暴力会超时
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int index = -1;
//         int sum = 0;

//         for (int i = 0; i < gas.size(); i++) {
//             // 从满足条件的位置出发， 看能不能走完一圈，如果中间出现负数就停止
//             index = (i + 1) % gas.size();
//             sum = gas[i] - cost[i];
//             while (sum > 0 && index != i) {
//                 sum += gas[index] - cost[index];
//                 index = (index + 1) % gas.size();  // 控制循环遍历数组
//             }
//             if (sum >= 0 && index == i) return index;
//         }
        
//         return -1;
//     }
// };

// // 贪心  出现curSum小于零，下一个点才有可能是起点，并更新curSum；若剩余的总和小于0，则不可能有满足条件的点
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int totalSum = 0;
//         int curSum = 0;
//         int index = 0;
//         for (int i = 0; i < gas.size(); i++) {
//             totalSum += gas[i] - cost[i];  // 从i点出发后的剩余邮箱
//             curSum += gas[i] - cost[i];
//             if (curSum < 0) {
//                 index = i + 1;  // 下一个点才有可能是起点
//                 curSum = 0;     // 更新从下一个点开始的油箱剩余油量
//             }
//         }
//         if (totalSum < 0) return -1;
//         return index;
//     }
// };

// 最小累加值的下一个坐标，即可以让最小值变大的坐标
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minSum = INT_MAX;
        int totalSum = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalSum += gas[i] - cost[i];
            if (totalSum < minSum) {   // 因为本题中只有唯一解，所以这个唯一解一定是最小和的下一个
                minSum = totalSum;
                index = i;
            }
        }
        return totalSum < 0 ? -1 : (index + 1) % gas.size();
    }
};


int main() {
    vector<int> gas = {10, 1, };
    vector<int> cost = {1, 1,};
    Solution su;
    int res = su.canCompleteCircuit(gas, cost);
    cout << res;
    return 0;
}