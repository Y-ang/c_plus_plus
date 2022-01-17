#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int start = 0, end = nums.size() - 1; start <= end, start >= 0; ){
            int mid = start + (end -start) / 2;
            if (nums[mid] == target){
                return mid;
            }else if (nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        
        return -1;
    }
};