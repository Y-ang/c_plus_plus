#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    return a[0] < b[0];
}

int main () {
    // int a, b;
    // while (cin >> a >> b)
    // {
    //     cout << a + b << endl;
    // }

    
    // int n;
    // cin >> n;
    // while (n--) {
    //     int a, b;
    //     cin >> a >> b;
    //     cout << a + b << endl;
    // }

    // int a, b;
    // while (cin >> a >> b && !( a == 0 && b == 0)) {
    //     cout << a + b << endl;
    // }

    // int n;
    // while (cin >> n && n != 0) {
    //     int cnt = 0;
    //     int a;
    //     while (n--) {
    //         cin >> a;
    //         cnt += a;
    //     }
    //     cout << cnt << endl;
    // }

    // int t;
    // cin >> t;
    // while (t--) {
    //     int n;
    //     cin >> n;
    //     int a;
    //     int cnt = 0;
    //     while (n--) {
    //         cin >> a;
    //         cnt += a;
    //     }
    //     cout << cnt << endl;
    // }
    
    
    // int n;
    // while (cin >> n) {
    //     int a;
    //     int cnt = 0;
    //     while (n--) {
    //         cin >> a;
    //         cnt += a;
    //     }
    //     cout << cnt << endl;
    // }

    // int sum = 0;
    // int n;
    // while (cin >> n) {
    //     sum += n;
    //     // cin >> n;
    //     if (getchar() == '\n') {
    //         cout << sum << endl;
    //         sum = 0;
    //     }
    // }

    // int n;
    // cin >> n;
    // vector<string> ss(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> ss[i];
    // }
    // sort(ss.begin(), ss.end(), cmp);
    // for (auto& s : ss) {
    //     cout << s << " ";
    // }

    // vector<string> str;
    // string s;
    // while (cin >> s) {
    //     str.push_back(s);
    //     if (getchar() == '\n') {
    //         sort(str.begin(), str.end());
    //         for (auto& s : str) {
    //             if ( s == "") break;
    //             cout << s << " ";
    //         }
    //         cout << endl;
    //         str.clear();
    //     }
    // }

    // string str;
    // while (getline(cin, str)) {
    //     stringstream ss;
    //     ss << str;

    //     string s;
    //     vector<string> vec;
    //     while (getline(ss, s, ',')) {
    //         vec.push_back(s);
    //     }

    //     sort(vec.begin(), vec.end());
    //     for (int i = 0; i < vec.size(); i++) {
    //         cout << vec[i];
    //         if (i != vec.size() - 1) cout << ',';
    //     }
    //     cout << endl;
    // }

    uint64_t a, b;
    while (cin >> a >> b) {
        uint64_t sum = a + b;
        cout << sum << endl;
    }

    return 0;
}