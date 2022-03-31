#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[0] > 0) return {};     // 排序后首元素大于0，就不会有满足和为0的三元组
            // 去重
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            
            for (int left = i + 1, right = nums.size() - 1; left < right; ){
                if (nums[left] + nums[right] + nums[i] == 0) {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // 去重
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;

                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                } else if (nums[left] + nums[right] + nums[i] > 0) {
                    right--;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {};
    Solution su;
    su.threeSum(nums);
    return 0;
}