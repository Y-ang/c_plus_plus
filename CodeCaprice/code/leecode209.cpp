#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> lengthList;
        int start = 0;
        int end = 0;
        int minLength = 0;
        int sum = nums[start];
        
        // if (nums[start] >= target){
        //     return 1;
        // }
        // end = start + 1;
        while(end < nums.size()){
            sum += nums[++end];
            if(sum >= target){
                if (end - start + 1 > minLength){
                    minLength = end - start + 1;
                    break;
                }
            }
        }
        if (minLength == 0 || minLength == 1){
            return minLength;
        }
        while(start < end && end < nums.size() - 1){
            start++;
            end++;
            if (sum - nums[start] + nums[end] >= target){
                while(start < end){
                    if(sum - nums[--start] >= target){
                        minLength--;
                        continue;
                    }else{
                        start++;
                    }
                }
            }
            
        }
            
        
        return minLength;
    }
};
int main(){
    Solution su;
    vector<int> arr = {1, 4, 4};
    int num = su.minSubArrayLen(4, arr);
    cout << num;
    return 0;
}