#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 去重
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                // 去重  需要注意：不和第一个数即nums[i]比较，所以从nums[i +1]不和nums[i]比较
                if (j != i+1 && nums[j] == nums[j - 1]) continue;

                for (int left = j + 1, right = nums.size() - 1; left < right; ) {
                    if (nums[i] + nums[j] == target - nums[left] - nums[right]) {   // 如果4个整数都加到一边会有整数溢出现象
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (nums[i] + nums[j] < target - nums[left] - nums[right]) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2, 2, 2, 2, 2};
    Solution su;
    su.fourSum(nums, 8);
    return 0;
}