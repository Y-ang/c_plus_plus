class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> unmap;  // 记录元素出现的次数
        for (int n : numbers) {
            unmap[n]++;
            if (unmap[n] > numbers.size() / 2) {
                return n;
            }
        }
        return 0;
    }
};