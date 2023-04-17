#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> func(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 && nums[-1 * nums[i] - 1] > 0) {
                nums[-1 * nums[i] - 1] *= -1;   // 值对应的下标
                continue;
            }
            if (nums[nums[i] - 1] < 0) continue;
            nums[nums[i] - 1] *= -1;   // 值对应的下标
        }
        for (int i= 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }

};

int main() {
    Solution su;
    // vector<int> nums({1 , 3, 4, 7, 8, 7, 4, 3});
    vector<int> nums({2, 1, 3, 3});
    vector<int> output = su.func(nums);
    for (auto& n : output) {
        cout << n << " ";
    }

    return 0;
}