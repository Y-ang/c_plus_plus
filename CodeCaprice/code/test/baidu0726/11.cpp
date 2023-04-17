#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> up;
    vector<int> down;

    int res = INT_MIN;

    for (int i =0 ; i < n; ++i) {
        cin >> up[n];
    }
    for (int i = 0; i <n; ++i) {
        cin >> down[n];
    }


    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        if (up[i] == down[i]) umap[up[i]]++;
        else {
            umap[up[i]]++;
            umap[down[i]]++;
        }
    }

    for (auto& um : umap) {
        if (um.second < n / 2) continue;
        for (int i = 0; i < n; ++i) {
            cout << 0 << endl;
            return 0;
        }
    }
    

    return 0;
}