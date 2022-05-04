
// 空间复杂度O(1)
/*
对于某一个位置 i，其实我们只关心 i - 1 位置的 counts 值是多少，所以可以用一个 pre 变量来维护前一个位置，这样可以省去一个 counts 数组的空间。

*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        // 计算每段0 1的个数，（本题是要求0 1连续的子串的数量）
        // 相邻0 1个数的最小值，就是这两个相邻0 1能组成的子数组的数量
       int pre = 0;
       int cur = 0;
       int res = 0;
       for (int i = 0; i < s.size(); ) {
           char ch = s[i];
           while (i < s.size() && s[i] == ch) {
               cur++;
               i++;
           } 
           res += min(pre, cur); // 计算第一组连续相同的数时，pre为0，res = 0
           pre = cur;
           cur = 0;
       }
       return res;
    }
};

// 空间复杂度O(n)
// class Solution {
// public:
//     int countBinarySubstrings(string s) {
//         // 计算每段0 1的个数，（本题是要求0 1连续的子串的数量）
//         // 相邻0 1个数的最小值，就是这两个相邻0 1能组成的子数组的数量
//         vector<int> cntNums;
//         for (int i = 0; i < s.size();) {
//             char ch = s[i];
//             int cnt = 0;
//             while (i < s.size() && s[i] == ch) {   // 统计连续的0或者1的数量
//                 cnt++;
//                 i++;
//             }
//             cntNums.push_back(cnt);
//         }
//         int res = 0;
//         for (int i = 1; i < cntNums.size(); ++i) {
//             res += min(cntNums[i - 1], cntNums[i]);
//         }
//         return res;
//     }
// };