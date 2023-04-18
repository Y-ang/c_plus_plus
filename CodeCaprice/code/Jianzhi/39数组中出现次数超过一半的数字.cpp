#include <bits/stdc++.h>
using namespace std;

// 摩尔投票法：不同则抵消，占半数以上的数字必然留到最后；若超过一半的数+1，其他数-1，则数组和必定大于零
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int vote = 0;  // 投票数，若当前投票数为0，则超一半的数在后面的数组里；若投票数大于零则设置的这个数为要找的数
       int x = 0;   // 从第一个数开始遍历数组，寻找“出现次数超一半”的数
       for (auto& n : nums) {
            if (vote == 0) x = n;
            vote += n == x ? +1 : - 1;  // 当前值等于假设值则+1， 当前数不等于假设值-1
       }
       return x;
    }
};

// 哈希表统计法
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> cnt;
        for (int &n : nums) {
            cnt[n]++;
            if (cnt[n] > size / 2) return n;
        }
        return -1;
    }
};

// 数组排序法
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main() {
    Solution2 su;
    vector<int> nums = {1,2,2,2,1};
    cout << su.majorityElement(nums) << endl;
    return 0;
}