#include <bits/stdc++.h>
using namespace std;

void adjustDown(vector<int>& nums, int index, int heapSize) {
    int left = 2 * index + 1;
    while (left < heapSize) {
        int largest = left + 1 < heapSize && nums[left] < nums[left + 1] ? left + 1 : left;
        if (nums[largest] < nums[index]) break;
        swap(nums[largest], nums[index]);
        index = largest;
        left = index * 2 + 1;
    }
}


void heapSort(vector<int>& nums) {
    int heapSize = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
        adjustDown(nums, i, heapSize);
    }
    swap(nums[0], nums[--heapSize]);
    while (heapSize > 0) {
        adjustDown(nums, 0, heapSize);
        swap(nums[0], nums[--heapSize]);
    }
}

int main() {
    vector<int> nums = {5, 1, 4, 8, 2};
    heapSort(nums);
    cout << 1 << endl;
    return 0;

}