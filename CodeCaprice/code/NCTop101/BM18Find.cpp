#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0 || target < array[0][0] || target > array[array.size() - 1][array[0].size() - 1]) return false;
        int x = array.size() - 1;
        int y = 0;
        while (x >= 0 && y <= array[0].size() - 1) {
            if (target == array[x][y]) {
                return true;
            } else if (target < array[x][y]) {
                x--;
            } else {
                y++;
            }
        }
        return false;

    }
};


int main() {
    vector<vector<int>> nums = {{}};
    Solution su;
    su.Find(16, nums);
    return 0;
}
