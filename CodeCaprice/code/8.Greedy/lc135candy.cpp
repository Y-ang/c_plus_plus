#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // 使用从前到后累加， 再从后向前累加的两次累加方法
        vector<int> candyNum(ratings.size(), 1);
        // 从前向后累加左 < 右，则右+1
        for (int i = 0; i < ratings.size() - 1; i++) {
            if (ratings[i] < ratings[i + 1]) {
                candyNum[i + 1]  = candyNum[i] + 1;
            }
        }
        // 从后向前遍历，左 > 右，则左+1
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyNum[i] = max(candyNum[i], candyNum[i + 1] + 1); // 取两次累加过程中的最大值
            }
        }
        int sum = 0;
        for (int i = 0; i < candyNum.size(); i++) {
            sum += candyNum[i];
        }
        return sum;
    }
};

int main() {
    Solution su;
    vector<int> can = {1,2,2};
    su.candy(can);
    return 0;
}