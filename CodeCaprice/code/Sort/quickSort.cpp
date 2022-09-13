/*
快排是从大到小划分，归并是从小到大合并
当小于区 大于区之间悬殊过多时，时间复杂读会变大，最坏的每次只能固定一个位置：即左边全是小于区或右边全是大于区，则O(N^2)

*/

#include<bits/stdc++.h>
using namespace std;
// #define random(a, b) (rand() % (b - a + 1) + a) 


// // 分三块，小于nums[right]在左边, 大雨nums[right]在中间，等于nums[right]在中间
// vector<int> partition(vector<int>& nums, int left, int right) {
//     int less = left - 1;  // 初始化时，大于区小于区内没有元素
//     int more = right;    
//     while (left < more) { // left没有遍历到大于区, left是当前数的位置
//         if (nums[left] > nums[right]) {   // 当前数和划分数比较
//             swap(nums[left], nums[--more]); // 当前值与more区域左一个值交换且more区域左移, 当前索引不动
//         } else if (nums[left] < nums[right]) {
//             swap(nums[left++], nums[++less]); // 当前值与less区域右一个值交换且less区域右移, 索引++
//         } else {
//             left++;
//         }
//     }
//     swap(nums[more++], nums[right]);  // more和right交换，more区向右移一位
//     return vector<int>{less, more};
// }

// void quickSort(vector<int>& nums, int left, int right) {
//     if (left >= right) return;
//     srand((int)time(NULL));
//     int randIndex = random(left, right);  // 随机选一个数作为比较数, 避免出现最坏情况
//     swap(nums[randIndex], nums[right]);
//     vector<int> p = partition(nums, left, right);  // 划分left-right范围内的数组
//     quickSort(nums, left, p[0]);
//     quickSort(nums, p[1], right);
// }

// int main () {
//     vector<int> nums = {1, 3, 2, 8, 4, 6, 10};
//     quickSort(nums, 0, nums.size() - 1);
//     for (int i = 0; i < nums.size(); i++) {
//         cout << nums[i] << endl;
//     }
//     return 0;
// }


// 荷兰国旗问题，比number小的在小于区，比number大的数在大于区，等于number的数在中间
vector<int> partition(vector<int>& nums, int left, int right, int number) {
    int less = left - 1;
    int more = right + 1;
    while (left < more) {
        if (nums[left] < number) swap(nums[left++], nums[++less]);
        else if (nums[left] > number) swap(nums[left], nums[--more]);
        else left++;
    }
    return vector<int>{less, more};
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    srand((int)time(NULL));
    int index = rand() % (right - left + 1) + left;  // 随机选一个数作为划分值
    vector<int> p = partition(nums, left, right, nums[index]);
    quickSort(nums, left, p[0]);
    quickSort(nums, p[1], right);
}

int main () {
    vector<int> nums = {1, 3, 2, 8, 4, 6, 10};
    quickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}