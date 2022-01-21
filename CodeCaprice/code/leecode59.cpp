#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> array(n, vector<int>(n,0));
        int startx, starty = 0;
        int loop = n/2;
        int offset = 0;
        int cnt = 1;
        while(loop--){
            int j, i;
            for(j = starty; j < starty + n - offset - 1; j++){
                array[startx][j] = cnt++;
            }
            for(i = startx; i < starty + n - offset - 1; i++){
                array[i][j] = cnt++;
            }
            for(; j > starty; j--){
                array[i][j] = cnt++;
            }
            for(; i > startx; i--){
                array[i][j] = cnt++;
            }
            offset += 2;
            startx++;
            starty++;
        }
    if (n%2 != 0){
        array[n/2][n/2] = cnt;
    }
    return array;
    }
};