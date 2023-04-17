#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<uint64_t> nums(n);
    uint64_t max_0 = 0;
    uint64_t max_1 = 0;
    uint64_t sum_0 = 0;
    uint64_t sum_1 = 0;
    int size_0 = 0;
    int size_1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (i % 2 == 0) {
            max_0 = max(nums[i], max_0);
            sum_0 += nums[i];
            size_0++;
        }
        else {
            max_1 = max(nums[i], max_1);
            sum_1 += nums[i];
            size_1++;
        }
    }
    uint64_t res = 0;
    res = max_0 * size_0 - sum_0 + max_1 * size_1 - sum_1;
    if (max_0 == max_1) res += n/2;
    cout << res << endl;
    return 0;
}


// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     set<int> set0; //偶数位置上的数 
//     set<int> set1; // 奇数位置上的数
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//         if (i % 2 == 0) set0.insert(nums[i]);
//         if (i % 2 == 1) set1.insert(nums[i]);
//     }

//     map<int, int> step0; // 偶数位置上,全部改为某个数的布长
//     map<int, int> step1; // 奇数位置上,全部改为某个数的布长
//     for (auto& target : set0) {
//         for(int i = 0; i < nums.size(); ++i) {
//             if (i % 2 == 0) {
//                 step0[target] += abs(target - nums[i]);
//             }
//         }
//     }
//     for (auto& target : set1) {
//         for(int i = 0; i < nums.size(); ++i) {
//             if (i % 2 == 1) {
//                 step1[target] += abs(target - nums[i]);
//             }
//         }
//     }

//     map<int, int> step00;
//     map<int, int> step11;
//     for (auto& step : step0) {
//         step00[step.second] = step.first; 
//     }
//     for (auto& step: step1) {
//         step11[step.second] = step.first;
//     }
//     int res = INT_MAX;
//     for (auto& s0 : step00) {
//         for (auto& s1 : step11) {
//             if (s0.second != s1.second) {
//                 res = s0.first + s1.first;
//                 break;
//             } else continue;
//         }
//         break;
//     }


//     // sort(step0.begin(), step0.end(), cmp);
    

//     return 0;
// }