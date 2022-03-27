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



class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        backtracking(1, n, k, {}, res);
        return res;
    }
    void backtracking(int startIndext, int n, int k, vector<int> path, vector<vector<int>>& res){
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = startIndext; i <= n - (k - path.size()) + 1; i++) {  // 剪枝 还需要k-path.size()个元素，所以集合最多只能从n - (k - path.size()) + 1 开始
            path.push_back(i);
            backtracking(i + 1, n, k, path, res);
            path.pop_back();
        }
    }
};