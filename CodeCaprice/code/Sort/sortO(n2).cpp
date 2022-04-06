#include<bits/stdc++.h>
using namespace std;


// 交换相邻元素 稳定
vector<int> bubbleSort(vector<int>& nums) {
    for (int end = nums.size() - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
    return nums;
}

// 如果某次一遍历时，没有出现交换，则表明数组已有序
vector<int> bubbleSort2(vector<int>& nums) {
    for (int end = nums.size() - 1; end > 0; end--) {
        int flag = true;
        for (int i = 0; i < end; i++) {
            if (nums[i] > nums[i + 1]) {
                flag = false;
                swap(nums[i], nums[i + 1]);
            }
        }
        if (flag) break;
    }
    return nums;
}


// 每次选择最小的放在该次遍历的首位置  不稳定
vector<int> selectionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int minIndex= i;
        for (int j = i + 1; j < nums.size(); j++) {
            minIndex = nums[j] < nums[minIndex] ? j : minIndex;
        }
        swap(nums[i], nums[minIndex]);
    }
    return nums;
}

//
vector<int> insertionSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        for (int j = i; j > 0&& nums[j - 1] > nums[j]; j--) {  // 只要后面一个数比前面一个数大了， 就停止交换
            swap(nums[j], nums[j - 1]);
        }
    }
    return nums;
}


vector<int> 

int main() {
    vector<int> nums = {3,2,6,1,9};
    insertionSort(nums);

    return 0;
}