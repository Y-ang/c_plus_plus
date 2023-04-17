#include<bits/stdc++.h>
using namespace std;

// 比较数组

class Solution {
public:
    int solve(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (cmp(nums[i], nums[j])) {
                    swap(nums[i], nums[j]);
                } 
            }
        }
        string res = "";
        for (int& n : nums) {
            res += to_string(n);
        }
        return stoi(res);
    }
    bool cmp (int num1, int num2) {
        string str1 = to_string(num1) + to_string(num2);
        string str2 = to_string(num2) + to_string(num1);
        if (str1 < str2) return false;
        return true;
    }
};

int main () {
    vector<int> nums= {3, 32, 332};
    Solution su;
    int res = su.solve(nums);
    cout << res << endl;
    return 0;
}