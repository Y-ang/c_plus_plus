#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums;
    for (int i = 0; i < nums.size(); i++) {
        int maxIndex = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[maxIndex]) {
                maxIndex = nums[j];
            }
        }
        swap()
    }
    return 0;
}