#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        // dp[i][j] 表示 0 - i-1 上的nums1的数组 和 0 - j-1 上的nums2的数组，的最长公共子序列为dp[i][j]
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1,0));
        for (int i = 1; i < nums1.size() + 1; i++) {
            for (int j = 1; j < nums2.size() + 1; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > res) res= dp[i][j];
            }
        }
        return res;
    }
};

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        vector<int> dp(nums2.size() + 1, 0);   // 一维数组
        for (int i = 1; i < nums1.size() + 1; i++) {
            for (int j = nums2.size(); j >= 1; j--) {   // 才后向前遍历，防止出现重复
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    dp[j] = 0;
                }
                if (dp[j] > res) res= dp[j];
            }
        }
        return res;
    }
};

int main() {

    return 0;
}