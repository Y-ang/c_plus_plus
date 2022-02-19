#include<bits/stdc++.h>
using namespace std;



// 双重循环 会超时
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        int hSize = haystack.size();
        int nSize = needle.size();
        for (int i = 0; i + nSize <= hSize; i++) {
            int flag = true;
            for (int j = 0; j < nSize; j++) {
                if (haystack[i+j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution su;
    su.strStr("mississippi", "issip");
    return 0;
}