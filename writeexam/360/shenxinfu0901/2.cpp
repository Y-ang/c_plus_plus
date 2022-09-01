#include <bits/stdc++.h>
using namespace std;

void output(vector<int>& nums) {
    for (auto& n : nums) {
        cout << n << " ";
    }
    cout << endl;
}

void adjust_up(vector<int>& nums, int size) {
    int index = size;
    if (nums[index] < nums[index - 1]) swap(nums[index], nums[index - 1]);
    while (nums[index] < nums[(index - 1) / 2]) {

        swap(nums[index], nums[(index - 1)/ 2]);
        index = (index - 1) / 2;
    }
}

int maxLen(vector<int>& nums, int size) {
    vector<int> dp(size);
    dp[0] = 0;
    int res = 0; 
    for (int i = 1; i < size; ++i) {
        if (nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 0;
        }
        cout << dp[i] << endl;
        res = max(res, dp[i]);
    }
    return res;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int size = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (size != 0) adjust_up(nums, size);
        output(nums);
        size++;
        res = max(res, maxLen(nums, size));
    }
    cout << res << endl;
    
    return 0;
}