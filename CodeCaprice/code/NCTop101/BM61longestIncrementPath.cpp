#include<bits/stdc++.h>
using namespace std;


// 记忆优化算法，使用深搜的过程中，节点会被多次访问，在节点第一次访问被访问时就记录下节点的最长路径，下次再访问到可以直接读取。
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m;
    int solve(vector<vector<int> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int res = 0;
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                res = max(res, dfs(i, j, memo, matrix));
            }
        }
        return res;
    }
    int dfs(int row, int col, vector<vector<int>>& memo, vector<vector<int>>& matrix) {
        if (memo[row][col] != 0) {
            return memo[row][col];   // 该节点已经被访问过，直接返回节点值
        }
        ++memo[row][col];
        for (int i = 0; i < 4; i++) {
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];
            if (newRow >= 0 && newRow < n && newCol >=0 && newCol < m && matrix[newRow][newCol] > matrix[row][col]) {
                memo[row][col] = max(memo[row][col], dfs(newRow, newCol, memo, matrix) + 1);
            }
        }
        return memo[row][col];
    }
};
// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      * 递增路径的最大长度
//      * @param matrix int整型vector<vector<>> 描述矩阵的每个数
//      * @return int整型
//      */
//     int solve(vector<vector<int> >& matrix) {
//         // write code here
//         int res = 0;
//         vector<vector<int>> vis(matrix.size(), vector<int>(matrix[0].size(), 0));
//         for (int i = 0; i < matrix.size(); i++) {
//             for (int j = 0; j < matrix[0].size(); ++j) {
//                 int tmp = 0;
//                 dfs(i, j, matrix, vis, tmp, 0);
//                 res = max(res, tmp);
//             }
//         }
//         return res + 1;
//     }
//     void dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>> vis, int& pre, int cur) {
//         if (x > matrix.size() || y > matrix[0].size()) {
//             cur = max(pre, cur);
//             pre = cur;
//             cur = 0;
//             return;
//         }
//         if (x > 0 && matrix[x - 1][y] > matrix[x][y] && vis[x - 1][y] == 0) {
//             vis[x - 1][y] = 1;
//             dfs(x - 1, y, matrix, vis, pre, cur + 1);
//             vis[x - 1][y] = 0;
//         } 
//         if (x < matrix.size() - 1 && matrix[x + 1][y] > matrix[x][y] && vis[x + 1][y] == 0) {
//             vis[x + 1][y] = 1;
//             dfs(x + 1, y, matrix, vis, pre, cur + 1);
//             vis[x + 1][y] = 0;
//         } 
//         if (y > 0 && matrix[x][y - 1] > matrix[x][y] && vis[x][y - 1] == 0) {
//             vis[x][y - 1] = 1;
//             dfs(x, y - 1, matrix, vis, pre, cur + 1);
//             vis[x][y - 1] = 0;
//         } 
//         if (y < matrix[0].size() - 1 && matrix[x][y + 1] > matrix[x][y] && vis[x][y + 1] == 0) {
//             vis[x][y + 1] = 1;
//             dfs(x, y + 1, matrix, vis, pre, cur + 1);
//             vis[x][y + 1] = 0;
//         } 
//         cur = max(pre, cur);
//         pre = cur;
//         cur = 0;
//         return;
//     }
// };

int main() {
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    Solution su;
    su.solve(nums);
    return 0;
}