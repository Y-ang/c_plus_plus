#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 找最大跳跃步数
        int cover = 0;
        for (int i = 0; i <= cover; i++) {  // 在可达cover范围内；不能用nums.size()作为终止条件，因为会出现在一个点无法调出循环的情况
            cover = max(i + nums[i], cover); // 跳到每个数组上的最远范围
            if (cover >= nums.size() - 1) { // 最远范围超过数组范围
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution su;
    vector<int> nums = {3,2,1,0,4};
    bool res = su.canJump(nums);
    cout << res;
    return 0;
}