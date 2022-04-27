#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        vector<int> used(str.size());
        sort(str.begin(), str.end());
        backtracking("", str, used, res);
        return res;
    }
    
    void backtracking(string permu,string str, vector<int>& used, vector<string>& res) {
        if (permu.size() == str.size()) {
            res.push_back(permu);
            return;
        } 
        for (int i = 0; i < str.size(); ++i) {
            if (used[i] == 1 || (i > 0 && str[i] == str[i - 1] && used[i - 1] == 0)) continue;  // 已经被使用 或者 当前作为重复项开始
            used[i] = 1;
            backtracking(permu + str[i], str, used, res);
            used[i] = 0;
        }
    }
    
};

int main () {

    return 0;
}