#include<bits/stdc++.h>
using namespace std;

// 方法一：找到范围内最远覆盖的点， 下一次就跳到该电上
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int res = 0;
//         int cover = 0;
//         int maxIndex = 0;
//         int maxCover = 0;
//         for (int i = 0; i <= cover; i++) {
//             if (i >= nums.size() - 1) break;
            
//             // 计算该cover内最大index
//             if (maxCover < i + nums[i]) {
//                 maxCover = i + nums[i];
//                 maxIndex = i;
//             }
//             // 转到最大index, 更新cover
//             if (i == cover) {
//                 i = maxIndex;  //跳到下一个点
//                 res++;
//                 cover = i + nums[i]; // 下一个点的范围
//                 maxIndex = 0;
//                 maxCover = 0;
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int nextIndex = 0;
        int curIndex = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            nextIndex = max(i + nums[i], nextIndex); //最远cover
            if (i == curIndex) {
                res++;
                curIndex = nextIndex;
            }
            // if (nextIndex >= nums.size() - 1) break; // 超过元素范围就退出, 因为次数是从起跳时开始算，当前跳已经能到达终点
        }
        return res;
    }
};

int main() {
    Solution su;
    vector<int> nums = {2,3,1,1,4};
    su.jump(nums);
    return 0;
}