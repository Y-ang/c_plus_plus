#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        vector<int> used(str.size(), 0);
        backtracking("", used, str, res);
        return res;
    }
    void backtracking(string path, vector<int> used, string str, vector<string>& res) {
        if (path.size() == str.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < str.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && used[i - 1] == 0 && str[i - 1] == str[i]) continue;
            used[i] = 1;
            backtracking(path + str[i], used, str, res);
            used[i] = 0;
        }
    }
};

int main () {

    return 0;
}