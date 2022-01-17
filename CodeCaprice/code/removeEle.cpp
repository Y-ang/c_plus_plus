#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //快慢指针法
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if (nums[fastIndex] != val){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex + 1;

        // 双指针法
        // int left = 0;
        // int right = nums.size() - 1;
        // while(left < right){
        //     if (nums[left] == val && nums[right] != val){
        //         int tmp = nums[left];
        //         nums[left] = nums[right];
        //         nums[right] = tmp;
        //         right--;
        //         left++;
        //     }else if(nums[left] == val && nums[right] == val){
        //         right--;
        //     }else{
        //         left++;
        //     }
        // }

        // // int left = 0；
        // // int right = nums.size() - 1;
        // // for (; left < right; end = right){
        // //     if (nums[left] == val && nums[right] == val){
        // //         right--;
        // //     }else if(nums[left] == val && nums[right] != val){
        // //         int tmp = nums[left];
        // //         nums[left] = nums[right];
        // //         nums[right] = tmp;
        // //         left++; right--;
        // //     }else{
        // //         left++;
        // //     }
        // // }
        // if (right != -1 && nums[right] == val){
        //     return right; 
        // }else{
        //     return right + 1;
        // }
    }
};
int main(){
    vector<int> array = {};
    Solution su;
    int len = su.removeElement(array, 2);
    cout << len << endl;
    return 0;
}