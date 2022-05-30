#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
            while (left < right && !isalnum(s[left])) left++;  // 忽略不是字母和数字的字符
            while (left < right && !isalnum(s[right])) right--;
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution su;
    su.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}