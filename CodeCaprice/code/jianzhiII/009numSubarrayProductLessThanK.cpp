class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
        满足条件的窗口内连续子数组的个数为窗口的长度
        */
        int left = 0;
        int right = 0;
        int res = 0;
        int multi = 1;
        while (right < nums.size()) {
            multi *= nums[right++]; // 左闭右开区间
            while (left < right && multi >= k) {
                multi /= nums[left++];
            }
            res += left < right ? right - left : 0;
        }

        
        return res;
    }
};