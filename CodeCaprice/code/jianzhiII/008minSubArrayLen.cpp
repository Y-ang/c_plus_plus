#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int res = nums.size() + 1;
        int winSum = 0;  // 窗口内数字和
        int winLen = 0;  // 窗口的大小
        while (right < nums.size()) {
            winSum += nums[right++];
            winLen++;
            while (winSum >= target) {
                res = min(res, winLen);
                winSum -= nums[left++];
                winLen--;
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};


int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution su;
    su.minSubArrayLen(11, nums);
    return 0;
}