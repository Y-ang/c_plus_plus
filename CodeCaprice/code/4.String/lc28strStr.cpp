#include<bits/stdc++.h>
using namespace std;



// 暴力解法 双重循环
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

// 暴力解法II
int search(String pat, String txt) {
    int M = pat.length;
    int N = txt.length; //文本长度，即haystack
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (pat[j] != txt[i+j])
                break;
        }
        // pat 全都匹配了
        if (j == M) return i;
    }
    // txt 中不存在 pat 子串
    return -1;
}

int main() {
    Solution su;
    su.strStr("mississippi", "issip");
    return 0;
}