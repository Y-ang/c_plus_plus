class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int, vector<int>, less<int>> priQue;
        for (auto& n : input) {
            priQue.push(n);
            if (priQue.size() > k) {
                priQue.pop();
            }
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0 && !priQue.empty() ; --i) {
            res[i] = priQue.top();
            priQue.pop();
        }
        return res;
    }
};