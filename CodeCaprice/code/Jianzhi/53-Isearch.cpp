#include <bits/stdc++.h>
using namespace std;


// // 方法一： 分别寻找target的左右边界
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int leftIdx = 0;
//         int rightIdx = 0;
//         // 寻找右边界
//         int left = 0;
//         int right = nums.size() - 1;
//         while (left <= right) {
//             int mid = left + ((right - left) >> 1);
//             if (nums[mid] <= target) left = mid + 1;
//             else right = mid - 1;
//         }
//         if (right < 0 || nums[right] != target) return 0;
//         rightIdx = right;

//         // 寻找左边界
//         left = 0;
//         right = nums.size() - 1;
//         while (left <= right) {
//             int mid = left + ((right - left) >> 1);
//             if (nums[mid] >= target) right = mid - 1;
//             else left = mid + 1;
//         }
//         leftIdx = left;

//         return rightIdx - leftIdx + 1;
//     }
// };

// 方法二： 寻找target的右边界，和target - 1的右边界
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return findRightBorder(nums, target) - findRightBorder(nums, target - 1);// 如果两个值在数组中都不存在，则他俩的右边界相同，返回0；如果其中一个不存在
    }

    int findRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // 左闭右开区间
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return left - 1;
    }
};

int main () {
    Solution su;
    vector<int> nums = {5,7,7,8,8,10};
    su.search(nums, 5);
    return 0;
}