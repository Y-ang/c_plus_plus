#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> orderNums(nums.size());
        int right = nums.size() - 1;
        for(int i = 0, j = nums.size() - 1; i <= j;){
            if(nums[i] * nums[i] >= nums[j] * nums[j]){
                orderNums[right--] = nums[i] * nums[i];
                i++;
            }else{
                orderNums[right--] = nums[j] * nums[j];
                j--;
            }
        }
        return orderNums;
        // vector<int> orderNums;
        // if (nums.size() == 1){
        //     return nums;
        // }
        // int min = nums.size() - 1;
        // for(int i = 0; i < nums.size(); i++){
        //     nums[i] *= nums[i];
        // }
        // for(int i = 0; i < nums.size(); i++){
        //     if(i - 1 >= 0 && nums[i] > nums[i-1]){
        //         min = i-1;
        //         break;
        //     }
        // }
        // if(min < 0){
        //     return {};
        // }
        // orderNums.push_back(nums[min]);
        // int left = min-1;
        // int right = min+1;
        
        // while(left >= 0 && right <= nums.size() - 1){
        //     if(nums[left] <= nums[right]){
        //         orderNums.push_back(nums[left]);
        //         left--;
        //     }else if(nums[left] > nums[right]){
        //         orderNums.push_back(nums[right]);
        //         right++;
        //     }
        // }
        // while(left >= 0){
        //     orderNums.push_back(nums[left--]);
        // }
        // while(right <= nums.size() - 1){
        //     orderNums.push_back(nums[right++]);
        // }
        // return orderNums;
    }

    void printNums(vector<int> arrtmp){
        for(int i = 0; i < arrtmp.size(); i++){
            cout << arrtmp[i] << ' ';
        }
        return;
    }

};

int main(){
    Solution su;
    vector<int> arr = {};
    vector<int> oderArr = su.sortedSquares(arr);
    su.printNums(oderArr);
    return 0;
}