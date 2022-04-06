#include<bits/stdc++.h>
using namespace std;

int main () {
    vector<int> nums;
    for (int end = nums.size() - 1; end > 0; end++) {
        for (int i = 0; i < end; i++) {
            if (nums[i] > nums[i+1]) {
                swap(nums[i], nums[i+1]);
            }
        }
    }
    return nums;

    return 0;
}