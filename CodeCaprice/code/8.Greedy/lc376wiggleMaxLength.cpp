#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int size = 0;
        int preDiff = 0; // 当前元素和前一个元素的差值
        int curDiff = 0; // 当前元素和后一个元素的差值
        for (int i = 0; i < nums.size() - 1; i++) { //最后一个元素不考虑， 默认为一个峰值
            curDiff = nums[i + 1] - nums[i];
            if ((curDiff < 0 && preDiff >= 0) || (curDiff > 0 && preDiff <= 0)) { // 只有当前元素与后一个元素不相等时，才会被考虑为峰值
                preDiff = curDiff;
                size++;
            }
        }
        size++; // 最后一个元素默认为一个峰值
        return size;
    }
};

int main() {
    Solution su;
    // vector<int> nums = {1,7,4,9,2,5};
    vector<int> nums = {0,0,0,0};
    su.wiggleMaxLength(nums);
    return 0;
}