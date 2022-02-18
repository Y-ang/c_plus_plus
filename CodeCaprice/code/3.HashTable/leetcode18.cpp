/*
 18. 四数之和
 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int left = j + 1, right = nums.size() - 1; left < right; ) {
                    long long sum = + nums[left] + nums[right];
                    if ( nums[i] + nums[j] == target - nums[left] - nums[right]) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++, right--;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
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