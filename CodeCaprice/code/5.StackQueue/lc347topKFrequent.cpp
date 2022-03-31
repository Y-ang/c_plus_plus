#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool cmp (int a, int b) {
//         return a > b;
//     }
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         if (nums.size() == 1) {
//             return vector<int> {nums[0]};
//         }
//         sort(nums.begin(), nums.end());
//         multimap<int, int> freq;
//         vector<int> res;
//         int cnt = 1;
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] == nums[i - 1]) {
//                 cnt++;
//             } else if (nums[i] != nums[i - 1]) {
//                 freq.insert(pair<int, int>(cnt, nums[i - 1]));
//                 cnt = 1;
//             }
//         }
//         freq.insert(pair<int, int>(cnt, nums[nums.size() - 1]));

//         map<int, int>::reverse_iterator rit = freq.rbegin();
//         while (k-- && rit != freq.rend()) {
//             res.push_back(rit->second);
//             rit++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    class cmp {
    public:
        bool operator () (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto n : nums) {  // 频率
            freq[n]++;
        }
        // 建立小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> priQue;
        for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            priQue.push(*it);
            if (priQue.size() > k) {
                priQue.pop();
            }
        }
        // 保存结果
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = priQue.top().first;
            priQue.pop();
        }
        return res;
    }
};

int main() {
    Solution su;
    // vector<int> nums = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    su.topKFrequent(nums, k);
    return 0;
}