class Solution {
private:
    class Myqueue {
    public:
        deque<int> q;
        void pop(int x) {
            if (!q.empty() && q.front() == x) {
                q.pop_front();
            }
        }
        int front() {
            return q.front();
        }
        void push(int x) {
            while (!q.empty() && q.back() < x) {
                q.pop_back();
            }
            q.push_back(x);
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        Myqueue myQue;
        for (int i = 0; i < k; i++) {
            myQue.push(nums[i]);
        }
        res.push_back(myQue.front());
        for (int i = k; i < nums.size(); i++) {
            myQue.pop(nums[i - k]);
            myQue.push(nums[i]);
            res.push_back(myQue.front());
        }
        return res;
    }
};