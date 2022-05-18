#include <bits/stdc++.h>
using namespace std;

/* 
1的个数
偶数：等于这个数的一半中的1的个数
奇数：比前一个数多一个1
所以我们可以得到如下的状态转移方程：

dp[i] = dp[i-1]，当i为奇数
dp[i] = dp[i/2]，当i为偶数
上面的方程还可进一步合并为：
dp[i] = dp[i/2] + i % 2

作者：Terry2020
链接：https://leetcode.cn/problems/w3tCBm/solution/rang-ni-miao-dong-de-shuang-bai-ti-jie-b-84hh/
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i >> 1] + i % 2;
        }
        return res;
    }
};