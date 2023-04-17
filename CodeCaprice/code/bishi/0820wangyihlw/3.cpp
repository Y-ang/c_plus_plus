#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int res = 0;
    int idx = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (i % 2 != 0 && str[i] != 'e') res++;
        else if (i%2 == 0){
            if (idx % 2 == 0 && str[i] != 'r') res++;
            else if (idx % 2 != 0 && str[i] != 'd') res++;
            idx++;
        }
    }
    int ans = 0;
    idx = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (i % 2 != 0 && str[i] != 'e') ans++;
        else if (i %2 == 0){
            if (idx % 2 == 0 && str[i] != 'd') ans++;
            else if (idx % 2 != 0 && str[i] != 'r') ans++;
            idx++;
        }
    }

    res = min(res, ans);
    cout << res << endl;

    return 0;
}