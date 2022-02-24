class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int slowIndex = 0;
        // for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
        //     if (nums[fastIndex] != val){
        //         nums[slowIndex++] = nums[fastIndex];
        //     }
        // }
        // return slowIndex;
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};