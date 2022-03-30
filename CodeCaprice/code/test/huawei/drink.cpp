#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (cin >> n && n != 0) {
        int res = 0;
        while (n > 2) {
            int drinkNum = n / 3;
            int rest = n % 3;
            res += drinkNum;
            n = drinkNum + rest;
        }
        if (n == 2) {
            res++;
        }
        cout << res << endl;;
    }

    return 0;
}