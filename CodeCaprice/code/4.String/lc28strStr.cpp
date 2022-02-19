#include<bits/stdc++.h>
using namespace std;



// 双重循环 会超时
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        int start = -1;

        for (int i = 0; i < haystack.size(); i++) {
        
            int hsIndex = i;
            int ndIndex = 0;
            start = i;
            while (hsIndex < haystack.size() && ndIndex < needle.size()) {
                if (haystack[hsIndex++] != needle[ndIndex++]) {
                    start = -1;
                    break;
                }
            }
            if (start == i && ndIndex != needle.size()) {
                start = -1;
            } else if (start == i && ndIndex == needle.size()) {
                return start;
            }
        }
        return start;

    }
};

int main() {
    Solution su;
    su.strStr("mississippi", "issip");
    return 0;
}