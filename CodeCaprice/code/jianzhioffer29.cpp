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
        int cnt = 0;
        int startx=0;
        int starty = 0;
        int width = row <= col ? row : col;
        int loop = width / 2; //循环次数为较短边的一半
        int offset = 0;
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
        if(width % 2 != 0){
            if(row > col){
                for(int i = startx; i <= startx + row - offset - 1; i++){
                    res[cnt++] = matrix[i][starty];
                }
            }else if(row < col){
                for(int i = startx; i <= startx + col - offset - 1; i++){
                    res[cnt++] = matrix[startx][i];
                }
            }else{
                res[cnt] = matrix[startx][starty];
            }
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
    vector<vector<int>> matrix_ = {{1, 2, 3, 4}, {4, 5, 6, 4}, {3, 4, 3, 6}};
    vector<int> array = su.spiralOrder(matrix_);
    su.printNums(array);
    return 0;
}