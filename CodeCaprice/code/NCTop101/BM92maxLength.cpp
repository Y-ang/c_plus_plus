#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& arr) {
        // 记录数组中元素出现的次数
        unordered_map<int, int> unmap;
        int res = 0;
        // 通过移动左右指针，保证窗口内的元素都只出现一次
        int left = 0;
        for (int right = 0; right < arr.size(); ++right) {
            unmap[arr[right]]++;
            while (unmap[arr[right]] > 1) {  // 当前元素出现两次
                unmap[arr[left++]]--;  // 移动左指针，直到右边的这个元素只在窗口内出现一次
            }
            res = max(res, right - left + 1); // 更新最大窗口大小
        }
        return res;
    }
};

int main() {
    vector<int> nums = {3,3,2,1,3,3,3,1};
    Solution su;
    int res = su.maxLength(nums);
    cout << res;
    return 0;
}