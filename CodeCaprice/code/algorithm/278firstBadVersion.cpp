#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n <= 1) return n;
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        if (left > n || isBadVersion(left) == false) return 0; // 如果left越界，或left所在版本无错误，则该系列产品中没有错误版本
        return left; // 跳出循环时 left = right = target
    }
};

