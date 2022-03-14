#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtracking(0, n, board, res);
        return res;
    }
    void backtracking(int row, int n, vector<string> board, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, n, board)) {
                board[row][i] = 'Q';
                backtracking(row + 1, n, board, res);
                board[row][i] = '.';
            }
        }
    }
    bool isValid(int row, int col, int n, vector<string> board) {
        // 判断同列
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // 判断左上角对角线
        for (int i = row - 1, j = col - 1; i >=0 && j>=0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // 判断右上对角线
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution su;
    su.solveNQueens(5);
    return 0;
}