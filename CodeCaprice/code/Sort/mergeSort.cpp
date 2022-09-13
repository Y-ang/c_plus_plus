#include<bits/stdc++.h>
using namespace std;

// void merge(vector<int>& nums, int left, int mid, int right) {
//     vector<int> tmp(right - left + 1);
//     int i = 0;
//     int start1 = left;     // 第一个区间
//     int start2 = mid + 1;  // 第二个区间

//     while (start1 <= mid && start2 <= right) {
//         tmp[i++] = nums[start1] <= nums[start2] ? nums[start1++] : nums[start2++];
//     }
//     while (start1 <= mid) {
//         tmp[i++] = nums[start1++];
//     }                                     // 这两个循环只会进行一次
//     while (start2 <= right) {
//         tmp[i++] = nums[start2++];
//     }

//     for (auto& n : tmp) {     // 合并后覆盖原数组
//         nums[left++] = n; 
//     }
//     return;
// }


// // 迭代版 每次
// void mergeSort(vector<int>& nums) {
//     int size = nums.size();
//     for (int width = 1; width < size; width *= 2) {   // 归并两个子序列的宽度
//         for (int i = 0; i < nums.size(); i += 2 * width) { // 子序列的left位置
//             merge(nums, i, min(i + width - 1, size - 1), min(i + 2*width - 1, size - 1));
//         }
//     }
//     return;
// }


// // 递归版 先排左边 再排右边 再合并
// void mergeSort(vector<int>& nums, int left, int right) {
//     if (left == right) {
//         return;
//     }
//     int mid = left + ((right - left) >> 1);
//     mergeSort(nums, left, mid);
//     mergeSort(nums, mid + 1, right);
//     merge(nums, left, mid, right);
// }

// int main () {
//     vector<int> nums = {4,2,6,2,7,8,3};
//     // mergeSort(nums);
//     mergeSort(nums, 0, nums.size() - 1);
//     return 0;
// }


void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> tmp(right - left + 1);
    int index = 0;
    int start1 = left;
    int start2 = mid + 1;
    while (start1 <= mid && start2 <= right) {
        tmp[index++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
    }
    while (start1 <= mid) {
        tmp[index++] = nums[start1++];
    }
    while (start2 <= right) {
        tmp[index++] = nums[start2++];
    }
    for (auto& n : tmp) {
        nums[left++] = n;
    }

}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + ((right - left) >> 1);
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int main () {
    vector<int> nums = {4,2,6,2,7,8,3};
    // mergeSort(nums);
    mergeSort(nums, 0, nums.size() - 1);
    return 0;
}