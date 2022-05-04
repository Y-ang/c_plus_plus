#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         if (obstacleGrid[0][0] == 1) return 0;
//         obstacleGrid[0][0] = 1;
//         for (int i = 0; i < obstacleGrid.size(); i++) { // row
//             for (int j = 0; j < obstacleGrid[0].size(); j++) { // col
//                 if ((i != 0 || j!= 0) && obstacleGrid[i][j] == 1) { // 第一个位置不改为0
//                     obstacleGrid[i][j] = 0;
//                     continue;
//                 }
//                 if (i == 0 && j != 0) obstacleGrid[0][j] = obstacleGrid[0][j - 1];// 第0行会出现障碍，障碍后的所有坐标与障碍相同，值都为0
//                 else if (j == 0 && i != 0) obstacleGrid[i][0] = obstacleGrid[i - 1][0]; // 第0列同上
//                 else if (i != 0 && j != 0) obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]; // 状态方程
//             }
//         }
//         return obstacleGrid[obstacleGrid.size() - 1].back();
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        // 第0行初始化
        for (int i = 0; i < obstacleGrid[0].size() && obstacleGrid[0][i] != 1; ++i) { // 遇到障碍就退出，后面都无法到达  
            dp[0][i] = 1;    // 没有障碍则赋值为1
        }
        // 第0列初始化
        for (int i = 0; i < obstacleGrid.size() && obstacleGrid[i][0] != 1; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] == 1) continue;    // 如果有障碍，到该点的路径数量为0   
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];   // 没有障碍
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
int main() {
    vector<vector<int>> nums = {{0,0}};
    Solution su;
    su.uniquePathsWithObstacles(nums);
    return 0;
}