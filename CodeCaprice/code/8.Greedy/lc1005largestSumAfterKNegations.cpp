# include<bits/stdc++.h>
using namespace std;


// 自己写的方法很啰嗦，因为考虑了大于0，小于0，等于零的情况
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 排序
        sort(nums.begin(), nums.end());
        // 若有负数，则把负数变整数
        // 若无负数，则改变最小值
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (k > 0) {           // 负数取正
                if (nums[i] < 0) {
                    if (i == nums.size() - 1) {  // k 大于数组的数量
                        if (k % 2 == 0) sum += nums[i];
                        else sum -= nums[i];
                    } else {
                        sum -= nums[i];
                        k--;
                    } 
                } else if (nums[i] == 0) {  // 取反到最小值为0，就只需在0上一直取反
                    k = 0;
                } else if (nums[i] > 0) {   // 要么最小的数是正数; 要么该数前一个是负数, 且前面的数都已经遍历为正数  --> 对最小数操作完就可以k=0
                    if (k % 2 == 0) sum += nums[i]; // k为偶数 无需改变
                    else if (i == 0){
                        sum -= nums[0];
                    } else { // 前面一个是负数
                        if (nums[i] + nums[i - 1] < 0) sum -= nums[i];
                        else {
                            sum += nums[i];
                            sum += 2*nums[i - 1];
                        }
                    }
                    k = 0;
                }
            } else {
                sum += nums[i];
            }
            
        }
        return sum;
    }
};


// 本问题的核心就是把负数变为正数, 剩余的都是正数时，对绝对值最小的数进行剩余操作
class Solution {
    static bool cmp (int a, int b) {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);  // 绝对值从大到小
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {  // 在k范围内， 把负数边正数，正数不变，
            if (k > 0 && nums[i] < 0) {
                nums[i] *= -1;
                k--;
            } 
        }
        if (k % 2 == 1) {   // 若还有k， 只变绝对值最小的
            nums[nums.size() - 1] *= -1;
        }
        for (int num : nums) sum += num;
        return sum;
    }
};


int main() {
    Solution su;
    vector<int> nums = {-8,3,-5,-5,2,-2};
    int k = 6; 
    su.largestSumAfterKNegations(nums, k);
    return 0;
}