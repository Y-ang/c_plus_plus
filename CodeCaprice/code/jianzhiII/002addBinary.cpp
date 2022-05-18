#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int enda = a.size() - 1;
        int endb = b.size() - 1;
        int carry = 0;
        while (enda >= 0 || endb >= 0 || carry == 1) {
            int val1 = enda >= 0 ? a[enda] - '0' : 0;
            int val2 = endb >= 0 ? b[endb] - '0' : 0;
            int sum = val1 + val2 + carry;
            
            res += sum % 2 == 1 ? '1' : '0';
            carry = sum / 2;

            if (enda >= 0) enda--;
            if (endb >= 0) endb--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution su;
    su.addBinary("11", "10");
    return 0;
}