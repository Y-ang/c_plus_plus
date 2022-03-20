#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        obstacleGrid[0][0] = 1;
        for (int i = 0; i < obstacleGrid.size(); i++) { // row
            for (int j = 0; j < obstacleGrid[0].size(); j++) { // col
                if ((i != 0 || j!= 0) && obstacleGrid[i][j] == 1) { // 第一个位置不改为0
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if (i == 0 && j != 0) obstacleGrid[0][j] = obstacleGrid[0][j - 1];// 第0行会出现障碍，障碍后的所有坐标与障碍相同，值都为0
                else if (j == 0 && i != 0) obstacleGrid[i][0] = obstacleGrid[i - 1][0]; // 第0列同上
                else if (i != 0 && j != 0) obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]; // 状态方程
            }
        }
        return obstacleGrid[obstacleGrid.size() - 1].back();
    }
};

int main() {
    vector<vector<int>> nums = {{0,1},{0,0}};
    Solution su;
    su.uniquePathsWithObstacles(nums);
    return 0;
}