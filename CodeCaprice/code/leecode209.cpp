#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 经典滑动窗口，先找到一个不小于target的子数组，通过头指针增加缩小窗口，知道该窗口内的子数组为小于target的子数组（这样就能找到一个满足target的最小窗口），然后尾指针不断增加，直到窗口内的数组重新满足target，重复循环。
        int start = 0;
        int sum = 0;
        int subLength = 0;
        int minLength = INT32_MAX;
        for(int end = 0; end < nums.size(); end++){
            sum += nums[end];
            while(sum >= target){
                subLength = end - start + 1;
                minLength = subLength < minLength ? subLength : minLength;
                sum -= nums[start++];
            }
        }
        return minLength == INT32_MAX ? 0 : minLength;
        
        
        // int start = 0;
        // int end = 0;
        // int minLength = 0;
        // int sum = nums[start];

        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] >= target){
        //         return 1;
        //     }
        // }

        // while(end < nums.size() - 1){
        //     sum += nums[++end];
        //     if(sum >= target){
        //         if (end - start + 1 > minLength){
        //             minLength = end - start + 1;
        //         }
        //         while(start <= end){
        //             if(sum - nums[start] >= target){
        //                 sum -= nums[start++];
        //                 minLength--;
        //             }else{
        //                 break;
        //             }
        //         }
        //         break;
        //     }
        // }
        // if (minLength == 0 || minLength == 1){
        //     return minLength;
        // }
        // while(start <= end && end <= nums.size() - 2){
        //     sum = sum - nums[start++] + nums[++end];
        //     while (sum >= target && start <= end){
        //         if(sum - nums[start] >= target){
        //             sum -= nums[start++];
        //             minLength--;
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return minLength;
    }
};
int main(){
    Solution su;
    vector<int> arr = {1,1,1,1,1};
    int num = su.minSubArrayLen(11, arr);
    cout << num;
    return 0;
}