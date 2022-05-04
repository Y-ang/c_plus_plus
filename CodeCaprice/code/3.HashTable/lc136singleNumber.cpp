#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto& n : nums) res ^= n;
        return res;
    }
};

int main() {

    return 0;
}