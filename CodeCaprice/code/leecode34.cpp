#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // int search(vector<int>& nums, int target, int left, int right, int flag){
    //     int mid = -1;
    //     while(left < right){
    //         mid = left + ((right - left) >> 1);
    //         if (nums[mid] == target){
    //             if (flag == 0){
    //                 right = mid;
    //             }else{
    //                 left = mid;
    //             }
    //         }else if(nums[mid] > target){
    //             right = mid - 1;
    //         }else{
    //             left = mid + 1;
    //         }
    //     }
    //     if (nums[mid] == target){
    //         return mid;
    //     }
    //     return -1;
    // }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        int low = -1;
        int hight = -1;
        // 找最小：从[left, right]区间中找，最终找到的元素的位置是偏小的；
        // 找最大：从[left, right)区间中找，最终找的元素位置是偏大的；
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                right = mid;
            }
        }
        if (right == left){
            low = right;
        }
        if (left > right){
            return {-1, -1};
        }

        left = 0;
        right = nums.size() - 1;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return {low, left - 1};
    }
};

int main(){
    Solution su;
    vector<int> num = {5,7,7,8,8,10};
    vector<int> array = su.searchRange(num, 6);
    return 0;
}