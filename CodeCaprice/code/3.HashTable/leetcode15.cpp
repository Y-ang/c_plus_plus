/*
    15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[0] > 0) {
                return {};
            }

            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int left = i + 1, right = nums.size() - 1; left < right; ) {
                if (nums[left] + nums[right] + nums[i] == 0) {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++, right--;
                    // 去重
                    while (left < right && nums[right] == nums[right + 1]) right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                } else {
                    right--;
                }
            }

        }
        return res;

    }
};