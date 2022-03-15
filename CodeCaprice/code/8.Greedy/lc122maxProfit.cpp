#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {  //从第二天开始计算
            int curDiff = prices[i] - prices[i - 1]; 
            if (curDiff > 0) {              //利润为正才相加
                res += curDiff;
            } 
        }
        return res;
    }
};

int main() {
    Solution su;
    vector<int> nums = {1};
    su.maxProfit(nums);
    return 0;
}