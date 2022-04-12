#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < nums.size() + 1; ++i) {
            if (nums[i - 1] == '0' && nums[i - 2] != '1' && nums[i - 2] != '2') return 0;  // 0字符前不是1或2，字符无法解码
            if (nums[i - 1] != '0' && nums[i - 2] != '0' && stoi(nums.substr(i - 2, 2)) <= 26) {  // 当前字符和前一个字符小于26，当前状态值既可以来自前一个状态+当前字符，也可以来自前二状态 + nums[i - 2] + nums[i - 1] (当前状态不能为0，即使0和前一个字符<26，也只有一种情况)
                dp[i] = dp[i - 2] + dp[i - 1];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[nums.size()];
    }
};

int main() {
    Solution su;
    string str = "101";
    su.solve(str);
    return 0;
}