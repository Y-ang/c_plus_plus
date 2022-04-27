class Solution {
public:
    vector<int> maxInWindows(const vector<int>& nums, int size) {
        deque<int> deq;
        vector<int> res;
        // 先遍历第一个窗口
        deq.push_back(nums[0]);
        for (int i = 1; i < size; i++) {
            while (!deq.empty() && nums[i] > deq.back()) { // 需要循环更换最大值，保证队列顶端为最大值
                deq.pop_back();
            } 
            deq.push_back(nums[i]);
        }
        res.push_back(deq.front()); // 保存第一个窗口的最大值
        // 滑动
        for (int i = size; i < nums.size(); i++) {
            if (deq.front() == nums[i - size]) deq.pop_front();
            while (!deq.empty() && nums[i] > deq.back()) { // 循环弹出前面的小值
                    deq.pop_back();
            }
            deq.push_back(nums[i]);
            res.push_back(deq.front());
        }
        return res;
    }
};