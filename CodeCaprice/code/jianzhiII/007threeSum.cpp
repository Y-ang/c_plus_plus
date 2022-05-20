#include <bits/stdc++.h>
using namespace  std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
            for (int left = i + 1, right = nums.size() - 1; left < right; ) {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    left++;
                    continue; // 去重
                }
                if (nums[i] + nums[left] == -nums[right]) 
                    res.push_back({nums[i], nums[left++], nums[right--]});
                else {
                    while (left < right && nums[i] + nums[left] < -nums[right]) left++;
                    while (left < right && nums[i] + nums[left] > -nums[right]) right--;
                }

            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-2,0,0,2,2};
    Solution su;
    su.threeSum(nums);
    return 0;
}