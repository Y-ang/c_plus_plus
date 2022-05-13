#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (numbers[mid] < numbers[right]) right = mid;
            else if (numbers[mid] > numbers[right]) left = mid + 1;
            else right--;   //如果中间元素等于右边元素，则最小值可能在左边也有可能在右边, 所以缩小区间：[2,2,2,0,1] [2,1,2,2,2,2]
        }
        return numbers[left];
    }
};