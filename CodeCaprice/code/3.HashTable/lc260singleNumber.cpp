#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (auto& n : nums) xorsum ^= n;
        int mask = xorsum == INT_MIN ? INT_MIN : xorsum & (-xorsum); // 最低的1位：一个数 & 该数的负数（补码+1） 得到最低位的1; INT_MIN不能对其取负数，会溢出
        vector<int> res = {0, 0};
        for (auto&n :nums) {
            // 出现两次的相同的元素肯定是出现在统一分组（他们与的结果相同），只出现一次的两个数会被分到不同的组
            if ( (n & mask) == 0) {    // 需要加括号，==号的优先级比&高
                res[0] ^= n;
            } else {
                res[1] ^= n;
            }
        }
        return res;
    }
};

int main() {
    Solution su;
    vector<int> nums = {1,2,1,3,2,5};
    su.singleNumber(nums);

    return 0;
}