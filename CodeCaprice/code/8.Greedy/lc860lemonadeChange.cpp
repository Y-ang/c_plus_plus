#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 找零的数目
        int cnt_5 = 0;
        int cnt_10 = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                cnt_5++;
            } else if (bills[i] == 10) {
                if (cnt_5 == 0) return false;
                cnt_10++;
                cnt_5--;
            } else {
                if (cnt_10 == 0 && cnt_5 < 3) return false; // 没有10，就要3张5
                if (cnt_5 == 0) return false; // 没有5就返回
                if (cnt_10 >= 1 && cnt_5 >= 1) {
                    cnt_10--;
                    cnt_5--;
                } else {
                    cnt_5 -= 3;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution su;
    vector<int> bills = {};
    su.lemonadeChange(bills);
    return 0;
}