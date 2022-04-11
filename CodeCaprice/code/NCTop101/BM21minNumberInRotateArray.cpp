#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        // 中间值和右端点进行比较
        int left = 0;
        int right = rotateArray.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);   // 左闭右开区间
            if (rotateArray[mid] > rotateArray[right]) {
                left = mid + 1;
            } else if (rotateArray[mid] < rotateArray[right]){
                right = mid;
            } else {
                right--;
            }
        }
        return rotateArray[left];  
    }
};

int main() {

    return 0;
}