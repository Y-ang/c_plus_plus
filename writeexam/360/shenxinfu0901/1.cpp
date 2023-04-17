#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<uint64_t> arr;
    uint64_t tmp;
    cin >> tmp;
    arr.push_back(tmp);
    while (getchar() != '\n') {
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    int k = arr.back();
    arr.pop_back();
    for (auto& n : arr) {
        cout << n << endl;
    }
    cout << k << endl;


    int index = 1;
    uint64_t res = arr[0];
    cout << "arr[0] " << arr[0] << endl; 
    cout << res << endl;
    while (k-- && index < arr.size()) {
        if (res < arr[index]) {
            res = arr[index];
            cout << res << endl;
        } 
        index++;
    }
    
    cout << res << endl;
    
    return 0;
}