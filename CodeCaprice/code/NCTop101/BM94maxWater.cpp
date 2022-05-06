class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int leftMax = 0, rightMax = 0;  // 左右两边最高的高度
        int res = 0;
        while (left <= right) { // 需要使用闭区间，因为相遇点的积水量也需要计算
            if (leftMax < rightMax) {   // 那边高度低计算哪边的积水量
                arr[left] < leftMax ? res += leftMax - arr[left] : leftMax = arr[left];
                left++;
            } else {
                arr[right] < rightMax ? res += rightMax - arr[right] : rightMax = arr[right];
                right--;
            }
        }
        return res;
    }
};