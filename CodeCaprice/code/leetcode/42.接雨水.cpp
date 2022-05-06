// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;   // 记录左右两边到当前位置的最高高度
        int res = 0;
        while (left <= right) {   // 注意这里是闭区间，因为在遍历的时候，左右指针相遇时，也需要判断相遇点是否会有积水
            if (leftMax < rightMax) {   // 当前的积水量取决于高度小的那一边: 如果当前高度比最高高度小，则增加积水量；否则更新高度
                height[left] < leftMax ? res += leftMax - height[left] : leftMax = height[left];
                left++;
            } else {
                height[right] < rightMax ? res += rightMax - height[right] : rightMax = height[right];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

