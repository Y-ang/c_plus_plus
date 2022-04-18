#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res = 0;
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return res;
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int start1 = left;
        int start2 = mid + 1;
        int index = 0;
        while (start1 <= mid && start2 <= right) {
            if (nums[start1] <= nums[start2]) {
                tmp[index++] = nums[start1++];
            } else {
                tmp[index++] = nums[start2++];
                res += mid - start1 + 1;  // 前面分块的值大于后面分块的值，则前面分块的该值后的所有值都大于当前后面分块的该值
            }
        }
        while (start1 <= mid) {   // 前面分块的值大，在上面的计算过程中已经记过数
            tmp[index++] = nums[start1++];
        }
        while (start2 <= right) {
            tmp[index++] = nums[start2++];
        }
        // 排序好的数拷贝到原数组
        for (auto& n : tmp) {
            nums[left++] = n;
        }
    }
};

int main() {
    Solution su;
    vector<int> nums = {1,3,2,3,1};
    int res = su.reversePairs(nums);
    cout << res;
    return 0;
}