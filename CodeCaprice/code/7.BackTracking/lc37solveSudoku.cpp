#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(0, board);
    }
    bool backtracking(int row, vector<vector<char>>& board) {
        if (row == 9) {
            return true;
        }
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (int num = 1; num <= 9; num++){
                    if (isValid(row, col, num, board)) {
                        board[row][col] = num + '0';
                        if (backtracking(row+1, board)) return true;
                        board[row][col] = '.';
                    }
                }
                
            }
        }
        return false;

    }
    bool isValid(int row, int col, int num, vector<vector<char>> board) {
        // 三公格没出现过num
        int xStart = (row / 3) * 3;
        int yStart = (col / 3) * 3;
        for (int i = xStart; i < xStart + 3; i++) {
            for (int j = yStart; j < yStart + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        // 同列没出现过num
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) {
                return false;
            }
        }
        // 同行没出现过num
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution su;
    vector<vector<char>> nums = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    su.solveSudoku(nums);
    return 0;
}