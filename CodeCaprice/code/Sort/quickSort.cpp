#include<bits/stdc++.h>
using namespace std;
#define random(a, b) (rand() % (b - a + 1) + a) 

vector<int> partition(vector<int>& nums, int left, int right) {
    int less = left - 1;
    int more = right;
    while (left < more) {
        if (nums[left] > nums[right]) {
            swap(nums[left], nums[--more]); // 当前值与more区域左一个值交换且more区域左移, 当前索引不动
        } else if (nums[left] < nums[right]) {
            swap(nums[left++], nums[++less]); // 当前值与less区域右一个值交换且less区域右移, 索引++
        } else {
            left++;
        }
    }
    swap(nums[more++], nums[right]);  // more和right交换，more区向右移一位
    return vector<int>{less, more};
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    srand((int)time(NULL));
    int randIndex = random(left, right);  // 随机选一个数作为比较数, 避免出现最坏情况
    swap(nums[randIndex], nums[right]);
    vector<int> p = partition(nums, left, right);  // 划分left-right范围内的数组
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