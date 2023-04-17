#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v1(n, 0);
    vector<int> v2(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v2[i];
    }
    unordered_map<int, int> hash;
    int max_val = -1;
    int max_cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (v1[i] == v2[i]) {
            hash[v1[i]] += 2;
            if (hash[v1[i]] > max_cnt) {
                max_cnt = hash[v1[i]];
                max_val = v1[i];
            }
            continue;
        }
        hash[v1[i]] += 2;
        hash[v2[i]] += 1;
        if (hash[v1[i]] > max_cnt) {
            max_cnt = hash[v1[i]];
            max_val = v1[i];
        }
        if (hash[v2[i]] > max_cnt) {
            max_cnt = hash[v2[i]];
            max_val = v2[i];
        }
    }
    int cnt_max_v1 = 0;
    for (int i = 0; i < n; ++i) {
        if (v1[i] == max_val)
            cnt_max_v1++;
    }
    int cnt_max_v2 = max_cnt - 2 * cnt_max_v1;
    int target = ceil(n * 1.0 / 2);
    int ans = target - cnt_max_v1;
    if (ans > cnt_max_v2)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}