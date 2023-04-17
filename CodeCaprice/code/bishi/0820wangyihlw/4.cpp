#include <bits/stdc++.h>
using namespace std;


void backtracking(int startIndex, vector<int>& nums, vector<int>& path, int& res) {
    if (path.size() == 3) {
        res++;
        return;
    }
    for (int i = startIndex; i < nums.size(); ++i) {
        if (path.size() == 0) {
            path.push_back(i + 1);
            backtracking(i+1, nums, path, res);
            path.pop_back();
        } else if (path.size() == 1){
            if (nums[i] < nums[path.back() - 1]) {
                path.push_back(i + 1);
                backtracking(i+1, nums, path, res);
                path.pop_back();
            } else continue;
        } else if (path.size() == 2) {
            if (nums[i] == nums[path[0] - 1]) {
                path.push_back(i + 1);
                backtracking(i+1, nums, path, res);
                path.pop_back();
            } else continue;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<int> indexVec;
    int res;
    backtracking(0, nums, indexVec, res);
    cout << res << endl;

    return 0;
}