// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

// 左边界： 查找比target小1的的第一个大于它的元素的下标
// 右边界：查找target的第一个大于它的元素的下标 - 1
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = search(nums, target - 1);
        int rightIndex = search(nums, target) - 1;
        if (leftIndex <= rightIndex && rightIndex < nums.size() && nums[leftIndex] == target) 
            return {leftIndex, rightIndex};
        return {-1, -1};
    }
    int search(vector<int>& nums, int target) {  // 查找第一个大于target的下标
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return left; // left指向target左边界的下一个元素的下标
    }
};

// @lc code=end

//version 2  分别寻找左右下标
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        // find left border
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        if (rightBorder - leftBorder < 2){
            return {-1, -1};
        }else{
            return {leftBorder + 1, rightBorder - 1};
        }
    }
private:
    int getLeftBorder(vector<int> nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        // int leftBorder = -1;
        int mid = 0;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return right;
    }
    int getRightBorder(vector<int> nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        // int rightBorder = -1;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if (nums[mid] <= target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};