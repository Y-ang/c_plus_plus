#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        int loop = s.size() / (2*k);
        int rest = s.size() % (2*k);
        while (loop--) {
            for (int left = loop * 2 * k, right = loop * 2 * k + k - 1; left < right; left++, right--) {
                swap(s[left], s[right]);
            }
        }
        if (rest != 0 && rest < k) {
            for (int right = s.size() - 1, left = right - rest + 1; left < right && left >= 0; left++, right--) {
                swap(s[left], s[right]);
            }
        } else if (rest != 0 && rest >= k) {
            for (int right = s.size() - 1 - (rest % k), left = right - k + 1; left < right && left >= 0; left++, right--) {
                swap(s[left], s[right]);
            }
        }
        return s;
    }
};

int main(){
    Solution su;
    string s = su.reverseStr("abcdefg", 3);
    for (int i = 0; i < s.size(); i++){
        cout << s[i] << ' ';
    }
    return 0;
}