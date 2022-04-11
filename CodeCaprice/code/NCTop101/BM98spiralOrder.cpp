#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row == 0) return {};
        int col = matrix[0].size();
        vector<int> res(row * col);
        int left = 0, right = col - 1; // 左右边界
        int top = 0, bottom = row - 1;    // 上下边界
        int index = 0;
        while (top < (row + 1) / 2 && left < (col + 1) / 2) {  // 退出循环的条件
            for (int i = left; i <= right; i++) {
                res[index++] = matrix[top][i];
            }
            for (int i = top + 1; i <= bottom; i++) {
                res[index++] = matrix[i][right];
            }
            for (int i = right - 1; top != bottom && i >= left; i--) {  // 如果top和bottom在同一行，会出现与第一次遍历重复重复
                res[index++] = matrix[bottom][i];
            }
            for (int i = bottom - 1; left != right && i > top; i--) {   // 如果出现left和right在同一行列，与第二个for循环重复
                res[index++] = matrix[i][left];
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> nums = {{2, 5, 8}, {4, 0, -1}};
    Solution su;
    su.spiralOrder(nums);
    return 0;
}