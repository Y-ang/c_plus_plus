class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();  // 每个元素走数组长度的步数都会回到原点
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        return;
    }
};