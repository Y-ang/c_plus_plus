#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res = 0;
    int InversePairs(vector<int> data) {
        mergeSort(data, 0, data.size() - 1);
        return res;
        
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int index = 0;
        int start1 = left;
        int start2 = mid + 1;
        while (start1 <= mid && start2 <= right) {
            if (nums[start1] < nums[start2]) {
                tmp[index++] = nums[start1++];
            } else {
                res += mid - start1 + 1;  // 左边从该元素后的所有元素，都比右边的当前元素大
                tmp[index++] = nums[start2++];
            }
        }
        while (start1 <= mid) {   // 右边的元素遍历完了，剩下左边的元素；证明右边小的元素都被处理过，不需要再进行处理
            tmp[index++] = nums[start1++];
        }
        while (start2 <= right) { // 剩下右边的元素，证明右边剩下的比左边的大，不需要任何处理
            tmp[index++] = nums[start2++];
        }
        for (auto& n : tmp) {
            nums[left++] = n;
        }
        return;
    }
};
int main () {
    vector<int> nums = {1,2,3,4,5,6,7,0};
    Solution su;
    su.InversePairs(nums);
    return 0;
}
