class Solution {
public:
    string solve(string s, string t) {
        if (s.empty()) return t;
        if (t.empty()) return s;
        string res;
        int sum = 0;
        int carry = 0;
        for (int i = s.size() - 1, j = t.size() - 1; i >= 0 || j >= 0 || carry != 0; ) {
            int val1 = i >= 0 ? s[i] - '0' : 0;
            int val2 = j >= 0 ? t[j] - '0' : 0;
            sum = val1 + val2 + carry;
            carry = sum / 10;
            sum %= 10;
            res += '0' + sum;
            if (val1 >= 0) i--;
            if (val2 >= 0) j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};