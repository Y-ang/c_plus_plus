class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) right = mid;  // 找第一个大于target的元素 <==> 找左边界
            else left = mid + 1;
        }
        return left;
    }
};