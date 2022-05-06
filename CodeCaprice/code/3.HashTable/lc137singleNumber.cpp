class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 对于出现三次的数，每一个二进制位上的和为0 或 3，则每个二进制位对3取余为0
        // 将所有数的二进制位相加，对3取余，则得到的余数就是只出现一次的元素的二进制位：要么为0要么为1
        int res = 0; 
        for (int i = 0; i < 32; ++i) {   // 整型数组有32位，分别计算每位上的二进制和
            int total = 0;
            for (auto& n : nums) {  // 计算二进制位上所有数的和
                total += (n >> i) & 1;   // 第i位上的和
            }
            res |= (total % 3) << i;  // 对3取余得到，得到结果的第i位上的二进制数
        }
        return res;
    }
};