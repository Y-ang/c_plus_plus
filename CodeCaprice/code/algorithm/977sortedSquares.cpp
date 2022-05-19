class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> orderNums(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int index = right;
        while (left <= right) {
            orderNums[index--] = -nums[left] > nums[right] ? nums[left] * nums[left++] : nums[right] * nums[right--];  // 去左边的负数就可以判断大小
        }
        return orderNums;
    }
};