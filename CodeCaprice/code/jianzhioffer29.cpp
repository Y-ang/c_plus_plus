#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = 0;
        if(row != 0){
            col = matrix[0].size();
        }else{
            return {};
        }
        vector<int> res(row*col, 0);
        int startx=0;
        int starty = 0;
        int loop = col/2;
        int offset = 0;
        int cnt = 0;
        while(loop--){
            int i,j;
            for(j = starty; j < starty + col - offset - 1; j++){
                res[cnt++] = matrix[startx][j];
            }
            for(i = startx; i < startx + row - offset - 1; i++){
                res[cnt++] = matrix[i][j];
            }
            for(; j > starty; j--){
                res[cnt++] = matrix[i][j];
            }
            for(; i > startx; i--){
                res[cnt++] = matrix[i][j];
            }
            offset += 2;
            startx++;
            starty++;
        }
        if(row == col && row%2 != 0){
            res[cnt] = matrix[row/2][row/2];
        }
        return res;
    }

    void printNums(vector<int> arrtmp){
        for(int i = 0; i < arrtmp.size(); i++){
            cout << arrtmp[i] << ' ';
        }
        return;
    }
};

int main(){
    Solution su;
    // vector<int> num = {5,7,7,8,8,10};
    // vector<int> array = su.searchRange(num, 8);
    vector<vector<int>> matrix_ = {{3},{2}};
    vector<int> array = su.spiralOrder(matrix_);
    su.printNums(array);
    return 0;
}