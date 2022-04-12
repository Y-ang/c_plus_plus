#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        // 贪心
        int sum = array[0];
        int maxSum = sum;

        for (int i = 1; i < array.size(); i++) {
            if (sum <= 0) {
                sum = array[i];
            } else {
                sum += array[i];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;


        // 动规
        int maxSum = array[0];
        for (int i = 1; i < array.size(); ++i) {
            array[i] = max(array[i], array[i - 1] + array[i]);
            maxSum = max(array[i], maxSum);
        }
        return maxSum;
    }
};

int main() {

    return 0;
}