#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 去除空格
        // 去除字符串头空格
        int fast = 0;
        while(fast < s.size() && s[fast] == ' ') {
            fast++;
        }
        // 去除中间元素的空格
        int slow = 0;
        for ( ; fast < s.size() - 1; fast++) {
            if (s[fast] != ' ' || (s[fast] == ' ' && s[fast + 1] != ' ')) { 
                s[slow++] = s[fast];
            } 
        }
        // 最后一个元素判断 slow保存的是去除多余空格后字符串长度
        if (s[s.size() - 1] != ' ') {
            s[slow++] = s[s.size() - 1];
        } 
        // 重新分配s内存
        s.resize(slow);

        // 反转整个串
        reverseStr(s, 0, s.size() - 1);
        // 反转单个串
        for (int left = 0, right = 0; left < s.size() && right < s.size(); right++) {
            if (s[right] == ' ') {
                reverseStr(s, left, right - 1);
                left = right + 1;
            } if (right == s.size() - 1) {
                reverseStr(s, left, right);
            }
        }
        return s;
    }
    void reverseStr(string& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};



int main() {
    Solution su;
    string s = "  fewefew  dfwec ";
    su.reverseWords(s);
    return 0;
}