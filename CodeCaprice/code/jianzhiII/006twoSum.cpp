class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res = {-1, -1};
        for (int left = 0, right = numbers.size() - 1; left < right; ) {
            if (numbers[left] == target - numbers[right]) return {left, right};
            else if (numbers[left] > target - numbers[right]) right--;
            else left++;
        }
        return res;
    }
};