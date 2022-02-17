/*
    349. 两个数组的交集
    给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int record[1000] = {0};
        vector<int> res;

        for (int i = 0; i < nums1.size(); i++) {
            record[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (record[nums2[i]] == 1){
                res.push_back(nums2[i]);
                record[nums2[i]] = 0;
            }
        }
        
        return res;

    }
};