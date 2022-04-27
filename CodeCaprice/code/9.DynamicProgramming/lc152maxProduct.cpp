#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 存在负值，会使前面的最大乘积变为最小乘积，所以要维护两个数组
        vector<int> dpMax(nums.size());
        vector<int> dpMin(nums.size());
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dpMax[i] = max({nums[i], nums[i] * dpMax[i - 1], nums[i] * dpMin[i - 1]}); // 数组需要连续
            dpMin[i] = min({nums[i], nums[i] * dpMax[i - 1], nums[i] * dpMin[i - 1]});
            res = max(res, dpMax[i]);
        }
        return res;
    }
};


int main () {
    vector<int> nums = {2,3,-2,4};
    Solution su;
    su.maxProduct(nums);
    return 0;
}