class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int res = max(maxRob(vector<int>(nums.begin(), nums.end() - 1)), 
                      maxRob(vector<int>(nums.begin() + 1, nums.end())));
        return res;       
    }
    int maxRob(vector<int> nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size() + 1);
        // 偷第一家
        dp[1] = nums[0];
        // 不偷最后一家
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        int res = dp[nums.size() - 1];
        dp.clear();
        // 不偷第一家
        dp[1] = 0;
        // 可以偷最后一家
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return max(res, dp[nums.size()]);
    }
};