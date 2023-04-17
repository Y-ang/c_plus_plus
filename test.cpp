#include <bits/stdc++.h>
using namespace std;


bool isvalid(vector<vector<int>>& path, int row, int col) {
    // int tmp = path[row][col];
    for (int i = 0; i < row; ++i) {
        if (path[i][col] == 1) return false;
    }
    // 左对角线
    for (int i = row - 1, j = col -1; i >= 0 && j >= 0; i--, j--) {
        if (path[i][j] == 1) return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < path[0].size(); i--, j++) {
        if (path[i][j] == 1) return false;
    }
    return true;
}


void backtracking(int startIdx, int n, int cnt, vector<vector<int>>& path) {
    if (cnt == n ) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        path[cnt][i] = 1;
        if (isvalid(path, cnt, i)) {
            backtracking(i + 1, n, cnt + 1, path);
        }
        path[cnt][i] = 0;
    }
    
}

void isNqueen(int n) {
//     vector<vector<int>> res;
    vector<vector<int>> path(n, vector<int>(n));
    backtracking(0, n, 0, path);
    return;
}


int main() {
    isNqueen(4);
    return 0;
}