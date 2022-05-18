#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string input = to_string(num);
        int ans = 0;
        for (int i = 0; i <= input.size() - k; ++i) {
            string tmp = input.substr(i, k);
            if (tmp != 0 && num % stoi(tmp) == 0) ans++;
            cout << "num:" << num << endl;
            cout << "tmp:" << stoi(tmp) << endl;
            cout << num % stoi(tmp) << endl;
        }
        return ans;
    }
};

int main() {
    Solution su;
    su.divisorSubstrings(430043,2);
    return 0;
}