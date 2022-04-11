#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    vector<int> solve(int n, int m, vector<int>& a) {
        // write code here
        if (m >= n && m % n == 0) return a;   // 移动位数为数组长度的整数倍
        m = m % n; // 移动的步数
        reverse(a, 0, n - 1);
        reverse(a, 0, m - 1);
        reverse(a, m, n - 1);
        return a;
    }
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};