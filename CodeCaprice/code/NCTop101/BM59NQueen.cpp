#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param n int整型 the n
     * @return int整型
     */
    int Nqueen(int n) {
        // write code here
        int res = 0;
        vector<int> pos(n, 0); // 记录每行皇后的位置
        backtracking(0, n, pos, res);
        return res;
    }
    void backtracking(int row, int n, vector<int>& pos, int& res) {
        if (row == n) {  // 每一行都摆上了皇后
            res++;
            return;
        }
        for (int i = 0; i < n; i++) {  // 每一行的皇后所摆放的列
            if (isValid(row, i, pos)) {   // 判断该行该列的皇后所放位置是否合理，只有这一行放成功了才能放下一行
                pos[row] = i;
                backtracking(row + 1, n, pos, res);
                pos[row] = -1;
            }
        }
    }
    bool isValid(int row, int col, vector<int>& pos) {
        for (int i = 0; i < row; i++) {
            if (pos[i] == col || abs(i - row) == abs(pos[i] - col)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution su;
    su.Nqueen(9);
    return 0;
}