#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    
    void backtracing(vector<int> combSet, int startIndex, int endIndex, int k, vector<vector<int>>& res) {
        output(combSet);
        if (combSet.size() == k) {
            res.push_back(combSet);
            return;
        }
        // endIndex 剪枝
        for (int i = startIndex; i <= endIndex - (k - combSet.size()) + 1; i++) {
            combSet.push_back(i);
            backtracing(combSet, i + 1, endIndex, k, res);
            combSet.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combSet;
        vector<vector<int>> res;
        backtracing(combSet, 1, n, k, res);
        return res;
    }
    void output(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution su;
    su.combine(5, 3);
    return 0;
}