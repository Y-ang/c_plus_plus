#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0; // 遍历数组
        int slow = 0; // fast遍历到非val值时，将值保存下来
        for (; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {1,2,1,1,2,2,3};
    int val = 2;
    Solution su;
    su.removeElement(nums, val);
    return 0;
}