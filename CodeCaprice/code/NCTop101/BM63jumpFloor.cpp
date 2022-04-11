#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if (number < 3) return number;
        int dp[2] = {1, 2};
        for (int i = 3; i <= number; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};