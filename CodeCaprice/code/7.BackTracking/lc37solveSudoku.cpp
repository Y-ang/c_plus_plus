#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
    bool backtracking(vector<vector<char>>& board) {
        for (int row = 0 ; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++){
                        if (isValid(row, col, ch, board)) {
                            board[row][col] = ch;
                            if (backtracking(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;

    }
    bool isValid(int row, int col, char num, vector<vector<char>> board) {
        // 三公格没出现过num
        int xStart = (row / 3) * 3;
        int yStart = (col / 3) * 3;
        for (int i = xStart; i < xStart + 3 ; i++) {
            for (int j = yStart; j < yStart + 3; j++) {
                if (board[i][j] == num) {
                    // cout << board[i][j];
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
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[0].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}