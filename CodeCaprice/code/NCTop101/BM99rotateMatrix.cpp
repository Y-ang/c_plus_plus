#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int>> mat, int n) {
        // write code here
        // 沿对角线交换元素
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j ++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // 反转每行的元素
        for (int i = 0; i < n; i++) {
            for (int left = 0, right = n - 1; left < right; left++, right--) {
                swap(mat[i][left], mat[i][right]);
            }
        }
        return mat;
    }
};


int main() {

    return 0;
}