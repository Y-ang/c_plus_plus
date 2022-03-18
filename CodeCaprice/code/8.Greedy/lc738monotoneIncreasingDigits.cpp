#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // 从后向前遍历数字每位数；前一个数比当前数大，则前一个数-1，当前数变为9
        string nStr = to_string(n);
        int flag = nStr.size();
        for (int i = nStr.size() - 1; i > 0; --i) {
            if (nStr[i - 1] > nStr[i]) {
                nStr[i - 1]--;
                flag = i;   // 注意这个时候不能直接赋值为9；需要标注到最先出现递减的数，其后所有的数都要变成9
            }
        }
        for (int i = flag; i < nStr.size(); i++) {
            nStr[i] = '9';
        }
    
        return stoi(nStr);

    }
};

int main() {
    int n = 100;
    Solution su;
    su.monotoneIncreasingDigits(n);

    return 0;
}