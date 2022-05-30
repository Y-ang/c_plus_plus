class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 将0转为-1，题目变成找出和为0的最长子数组的长度
        unordered_map<int, int> umap{{0, -1}}; // 数组中没有元素时，和为0，下标为-1
        int res = 0;
        int preSum = 0; // nums[i]前缀和
        for (int i = 0; i < nums.size(); ++i) {
            preSum += nums[i] == 0 ? -1 : 1;
            if (umap.find(preSum) != umap.end()) {
                res = max(res, i - umap[preSum]); // 找到前缀和为preSum的子数组的下标
            } else {
                umap[preSum] = i;  // 将当前前缀和和下标加入到哈希表中
            }
        }
        return res;
    }
};