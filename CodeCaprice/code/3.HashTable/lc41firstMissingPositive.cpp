#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 最小数在[1, N+1]范围内
        // 遍历数组，把num[i]上的数放到num[i] - 1位置上
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] >=1 && nums[i] <= nums.size() && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {    // 数字在数组长度范围内，数字换到指定下标就结束；如果交换位置上的两个数字相同，停止交换例 [1,1]
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // 遍历数组，找到第一个不在i-1位置上的数
        for (int i = 0; i < nums.size(); ++i) {  
            if (nums[i] != i + 1) {    // 不使用nums[i] - 1 != i，因为nums[i]位INT_MIN时，会溢出
                return i + 1;
            }
        }
        // 所有的数都在自己的位置上，则最小的数是size + 1
        return nums.size() + 1;
    }
};

int main() {
    vector<int> nums = {0};
    Solution su;
    su.firstMissingPositive(nums);
    return 0;
}