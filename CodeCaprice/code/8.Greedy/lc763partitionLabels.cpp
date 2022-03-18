#include<bits/stdc++.h>
using namespace std;

// 找每个字符出现的区间，并找出重复区间的最大和最小下标，遇到不重复的区间时，把前面的下标相见，就得到前面字符串的长度
// class Solution {
// public:
//     static bool cmp (const vector<int>& a, const vector<int>& b) {
//         return a[0] < b[0];
//     }
//     vector<int> partitionLabels(string s) {
//         // 字母出现的区间
//         vector<vector<int>> intervals(26, vector<int>{-1, -1});
//         vector<int> res;

//         // 找出字母出现的区间
//         for (int i = 0; i < s.size(); i++) {
//             if (intervals[s[i] - 'a'][0] == -1) {  // 最小左坐标
//                 intervals[s[i] - 'a'][0] = i;
//                 intervals[s[i] - 'a'][1] = i; // 会有只出现一次的字母，这个时候左右下标相同
//             } else {
//                 intervals[s[i] - 'a'][1] = i;   // 不断更新右坐标
//             }
//         }
//         // 找出重合的最大区间
//         sort(intervals.begin(), intervals.end(), cmp);
//         int preMin = 0;
//         int preMax = 0;
//         int cnt = 0;
//         for (auto& interval : intervals) {
//             if (interval[0] == -1) continue; // 这个字母没有出现过
//             if (preMax < interval[0]) { // 没有重叠的
//                 res.push_back(preMax - preMin + 1);
//                 preMin = interval[0];
//                 preMax = interval[1]; 
//             } else { // 有重叠
//                 preMax = max(preMax, interval[1]);  // 保存最远范围
//             }
//         }
//         //最后一个元素
//         res.push_back(preMax - preMin + 1);
//         return res;
//     }
// };


// 记录最远下标，不断更新现在遇到的最远下标。直到到达最远下标。这个下标就是当前字符串最后出现的重复字符
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;   // 记录字母出现的最远下标
        }
        // 遍历数组，看该字母出现的区间内，什么时候到达字母的最远下标
        vector<int> res;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']); // 不断更新最远下标
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution su;
    string s = "eaaaabaaec";
    su.partitionLabels(s);

    return 0;
}