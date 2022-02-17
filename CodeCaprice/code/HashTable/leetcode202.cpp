#include <bits/stdc++.h>
using namespace std;

/*
    202. 快乐数
    编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

本题的突破口为 “不是快乐数则会**无限循环**”，即不是快乐数就会有重复

*/

class Solution {
public:
    bool isHappy(int n) {
        set<long long> sum;
        sum.insert(n);

        while (true) {
            long long newSum = 0;
            while (n != 0){
                newSum += pow(n%10, 2);
                n /= 10;
            }
            if (newSum == 1){
                return true;
            }
            if (sum.find(newSum) != sum.end()){
                return false;
            }
            sum.insert(newSum);
            n = newSum;
        }
        
        return false;

    }
};

int main(){
    Solution su;
    bool res = su.isHappy(19);
    cout << res;
    return 0;
}