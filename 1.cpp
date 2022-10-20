


// 输入: nums = [1,1,1,2,2,3], k = 2
//  [1,2]

#include <bits/stdc++.h>
using namespace std;

class cmp {
    bool operator () (pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

};


vector<int> solve(vector<int>& nums, int k) {
    vector<int> res(k);
    unordered_map<int, int> hash;
    for (auto& n : nums) {
        hash[n]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>, cmp>> topK;
    for (auto& h : hash) {
        topK.push(h);
        if (topK.size() >= k) {
            topK.pop();
        }
    }

    for (int i = k - 1; i >= 0; --i)  {
        res[i] = topK.top().first;
        topK.pop();
    }   



    return res;
}


int main() {

    vector<int> nums= {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = {};
    res = solve(nums, k);
    return 0;
}
