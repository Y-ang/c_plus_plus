#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int minNumberDisappeared(vector<int>& nums) {
        // 最小正整数在[1, N+1]范围内
        // 遍历数组，把数字调整到对应位置
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // 返回第一个不在对应位置上的元素下标+1
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        // 数组中元素就位，最小整整谁为N+1
        return nums.size() + 1;
    }
};

int main() {

    return 0;
}