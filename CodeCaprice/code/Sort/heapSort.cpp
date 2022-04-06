#include<bits/stdc++.h>
using namespace std;

// 向下调整：根节点和左右孩子比较，调整以某一节点为根的子树为大根/小根堆; 向下调整需要一个堆大小的边界值以停止循环
void adjustDownHeap(vector<int>& nums, int index, int heapSize) {  
    int left = 2 * index + 1;
    while (left < heapSize) {
        int largest = left + 1 < heapSize && nums[left + 1] > nums[left] 
                        ? left + 1
                        : left;
        if (nums[index] > nums[largest]) break; // 根节点的值大于左右子节点，该树为大根堆，停止调整
        // 左右子树中有比根节点大的，继续向下调整
        swap(nums[index], nums[largest]);  
        index = largest;
        left = 2 * index + 1;
    }
}
// 向上调整：该节点与父节点比较，使该节点之间的树为大根/小根堆
void adjustUpHeap(vector<int>& nums, int index) {
    while (nums[index] > nums[(index - 1) / 2]) { 
        swap(nums[index], nums[(index - 1) / 2]);
        index = (index - 1) / 2;  // 到根节点，即index = 0时， (index - 1) / 2 = 0;
    }
}

void heapSort(vector<int>& nums) {
    int heapSize = nums.size();   // 比最大下标大1

    // 建立大根堆，法一：向上调整
    // O(nlogn) 对每个加入的元素做向上调整
    for (int i = 0; i < nums.size(); i++) {
        adjustUpHeap(nums, i);
    }

    // 建立大根堆，法二：向下调整
    // // O(n)  已知整个排序数组, 从叶子节点向上对每个节点向下调整
    for (int i = nums.size() - 1; i >= 0; i--) {
        adjustDownHeap(nums, i, heapSize);  // 从叶子节点开始，逐个向下调整，构建一个大根堆
    }
    
    
    // O(nlogn)
    swap(nums[0], nums[--heapSize]); // 堆首元素和尾元素交换，最大值到末尾，堆长度减一
    while (heapSize > 0) {                  // O(n)
        adjustDownHeap(nums, 0, heapSize);  // O(logn)
        swap(nums[0], nums[--heapSize]);
    }

}


int main(){
    vector<int> nums = {3, 2, 5, 4, 1, 9};
    heapSort(nums);

    return 0;

}