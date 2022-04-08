#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int solve(vector<vector<int> >& matrix) {
        // write code here
        int res = 0;
        vector<vector<int>> vis(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int tmp = 0;
                dfs(i, j, matrix, vis);
                res = max(res, tmp);
            }
        }
        return res;
    }
    void dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>> vis) {
        if (x > matrix.size() || y > matrix[0].size()) return;
        if (x > )
    }
};