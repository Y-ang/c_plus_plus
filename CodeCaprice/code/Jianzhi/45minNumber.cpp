#include<bits/stdc++.h>
using namespace std;

/* 
    题目：输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
    本题主要考察排序算法，使用不同的排序算法，将数组中的字符串按照 x + y < y + x 的顺序排序
    step1 先将整型数组转换为字符串数组以进行比较
    step2 根据x + y < y + x 的排序规则进行排序
    step3 拼接数组返回
*/

// 快排  手写快排
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto& n : nums) strs.push_back(to_string(n));
        quickSort(strs, 0, strs.size() - 1);
        string res;
        for (auto& str : strs) res += str;
        return res;
    }

    void quickSort(vector<string>& strs, int left, int right) {
        if (left >= right) return;
        // 随机选择划分值
        srand((int)time(NULL));
        int randIndex = rand() % (right - left + 1) + left;
        swap(strs[randIndex], strs[right]);
        // 根据划分值，划分左小右大区间
        vector<int> p(2);
        p = partition(strs, left, right);
        // 左右快排
        quickSort(strs, left, p[0]);
        quickSort(strs, p[1], right);
    }

    vector<int> partition(vector<string>& strs, int left, int right) {
        int less = left - 1;  // 小于区
        int more = right;     // 大于区
        while (left < more) { // 遍历到大于区前一个
            if (strs[left] + strs[right] < strs[right] + strs[left]) swap(strs[left++], strs[++less]);
            else if (strs[left] + strs[right] > strs[right] + strs[left]) swap(strs[left], strs[--more]);
            else left++;
        }
        swap(strs[more++], strs[right]);
        return {less, more}; // 返回小于区、大于区
    }
};

// 快排  内嵌快排
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto& n : nums) strs.push_back(to_string(n));
        sort(strs.begin(), strs.end(), [] (const string& a, const string& b) { return a + b < b + a;});
        string res;
        for (auto& str : strs) res += str;
        return res;
    }
};

// // 归并
// class Solution {
// public:
//     string minNumber(vector<int>& nums) {

//     }
// };

// // 堆排
// class Solution {
// public:
//     string minNumber(vector<int>& nums) {

//     }
// };

int main() {
    vector<int> nums = {1, 2, 3};
    Solution su;
    string res = su.minNumber(nums);
    cout << res << endl;
    return 0;
}