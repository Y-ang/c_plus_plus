#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0; 
        vector<long long> forwordSum(nums.size());
        vector<long long> backwordSum(nums.size());
        forwordSum[0] = nums[0];
        backwordSum[nums.size() - 1] = nums.back();
        for (int i = 1; i < nums.size(); ++i) {
            forwordSum[i] = forwordSum[i - 1] + nums[i];
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            backwordSum[i] = backwordSum[i + 1] + nums[i];
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (forwordSum[i] >= backwordSum[i + 1]) ans++;
        }
        return ans;
    }
};

int main() {
    return 0;
}