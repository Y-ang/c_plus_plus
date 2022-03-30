#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int sum = 0;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                sum += pow(16, s.size() - 1 - i) * (s[i] - '0');
            } else {
                sum += pow(16, s.size() - 1 - i) * (10 + (s[i] - 'A'));
            }
        }
        cout << to_string(sum) << endl;
    }
    
    return 0;
}