#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) return nums[i];  // nums[i] 位置上已经出现了nums[i], 找到重复
                swap(nums[i], nums[nums[i]]);
            } 
        }
        return -1;
    }
};