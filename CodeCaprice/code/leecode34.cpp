#include<iostream>
#include<vector>
using namespace std;

class Solution {

// version 1
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int left = 0;
//         int right = nums.size() - 1;
//         int mid = 0;
//         int low = -1;
//         int hight = -1;
//         // 找最小：从[left, right]区间中找，最终找到的元素的位置是偏小的；
//         while(left <= right){
//             mid = left + ((right - left) >> 1);
//             if(nums[mid] < target){
//                 left = mid + 1;
//             }else if(nums[mid] > target){
//                 right = mid - 1;
//             }else{
//                 right = mid;
//             }
//             if(left == right && right == mid){
//                 low = right;
//                 break;
//             }
//         }
//         if (left > right){
//             return {-1, -1};
//         }

//         // left = right;
//         right = nums.size() - 1;
//         while(left <= right){
//             mid = left + ((right - left) >> 1);
//             if(nums[mid] < target){
//                 left = mid + 1;
//             }else if(nums[mid] > target){
//                 right = mid - 1;
//             }else{
//                 left = mid;
//             }
//             if (nums[right] == target){
//                 return {low, right};
//             }else if(left == right -1 && nums[left] == target){
//                 return {low, left};
//             }
//         }
//         return {-1, -1};
//     }

//version 2
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

int main(){
    Solution su;
    // vector<int> num = {5,7,7,8,8,10};
    // vector<int> array = su.searchRange(num, 8);
    vector<int> num = {1};
    vector<int> array = su.searchRange(num, 1);
    return 0;
}