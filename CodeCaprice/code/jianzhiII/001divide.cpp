#include <bits/stdc++.h>
using namespace std;
/* 
参考 ： https://leetcode.cn/problems/xoh6Oh/solution/jian-dan-yi-dong-javac-pythonjs-zheng-sh-e8r6/
 */


// O(1)
class Solution {
public:
    int divide(int a, int b) {
        /* 
        a b中有一个是负数，则结果是负数
        如果两个同号，则结果是正数
         */
        // 异或 标记a 和 b是否同号  相同为0相异为1
        int sign = (a > 0) ^ (b > 0) ? -1 : 1;
        // 被除数 INT_MIN绝对值会越界
        if (a == INT_MIN) {
            if (b == 1) return INT_MIN;
            else if (b == -1) return INT_MAX;
        }
        // 负数变成正数会出现最小值取反越界，所以把所有正数转换为负数
        if (a > 0) a = -a;
        if (b > 0) b = -b;
        int cnt = 0;
        while (a <= b) { // a b是负数，是小于
            int value = b; // 每次减去的值
            int k = 1; //减去几个b
            // 0xc0000000 是十进制 -2^30 的十六进制的表示
            while (value >= 0xc0000000 && a <= value + value) {   // 成倍减去b看最多能减多少个b
                value += value;
                // 代码优化：如果 k 已经大于最大值的一半的话，那么直接返回最小值
                // 因为这个时候 k += k 的话肯定会大于等于 2147483648 ，这个超过了题目给的范围
                if (k > INT_MAX / 2) return INT_MIN;
                k += k;
            }
            a -= value;
            cnt += k;
        }
        return sign == 1 ? cnt : -cnt;
    }
};

// O(logN * logN)
class Solution {
public:
    int divide(int a, int b) {
        // 边界条件判断
        if (b == 0) return 0;
        if (b == 1) return a;
        if (b == -1) {
            return a == INT_MIN ? INT_MAX : -a;
        }
        /* 
        a b中有一个是负数，则结果是负数
        如果两个同号，则结果是正数
         */
        // 异或 标记a 和 b是否同号  相同为0相异为1
        int sign = (a > 0) ^ (b > 0) ? -1 : 1;
        // 负数变成正数会出现最小值取反越界，所以把所有正数转换为负数
        if (a > 0) a = -a;
        if (b > 0) b = -b;
        int quotient = 0;
        while (a <= b) { // a b是负数，是小于
            int divisor = b; // 每次减去的值
            int base = 1; //减去几个b
            // 使用减法避免溢出
            while (a - divisor <= divisor) {   // 成倍减去b看最多能减多少个b
                divisor += divisor; // 成倍增加
                base += base;
            }
            a -= divisor;
            quotient += base;
        }
        return sign == 1 ? quotient : -quotient;
    }
};

// O(n)的复杂度，被除数是最大值/最小值时，会出现超时现象
class Solution {
public:
    int divide(int a, int b) {
        /* 
        a b中有一个是负数，则结果是负数
        如果两个同号，则结果是正数
         */
        // 异或 标记a 和 b是否同号  相同为0相异为1
        int sign = (a > 0) ^ (b > 0) ? -1 : 1;
        // 被除数 INT_MIN绝对值会越界
        if (a == INT_MIN) {
            if (b == 1) return INT_MIN;
            else if (b == -1) return INT_MAX;
        }
        
        // 负数变成正数会出现最小值取反越界，所以把所有正数转换为负数
        if (a > 0) a = -a;
        if (b > 0) b = -b;
        int cnt = 0;
        while (a <= b) { // a b是负数，是小于
            a -= b;
            cnt++;
        }
        return sign == 1 ? cnt : -cnt;
    }
};