#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int cnt = 0;
        ans = INT_MAX;
        for (int i = 0; i < grid[0].size(); ++i) {
            dfs(grid, moveCost, 1, grid[0][i], grid[0][i]);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int level, int& cnt, int lastVal) {
        if (cnt >= ans)
            return ;
        if (level == grid.size()) {
            ans = min(ans, cnt);
            return ;
        }
        for (int i = 0; i < grid[level].size(); ++i) {
            cnt += grid[level][i];
            cnt += moveCost[lastVal][i];
            dfs(grid, moveCost, level + 1, cnt, grid[level][i]);
            cnt -= moveCost[lastVal][i];
            cnt -= grid[level][i];
        }
    }
};

int main () {
    Solution solution;
    vector<vector<int>> grid = {
        {5,3},{4,0},{2,1}
    };
    vector<vector<int>> moveCost = {
         {9,8},{1,5},{10,12},{18,6},{2,4},{14,3}
    };
    cout << solution.minPathCost(grid, moveCost) << endl;
    return 0;
}