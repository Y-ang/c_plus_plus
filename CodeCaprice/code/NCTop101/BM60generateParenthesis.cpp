class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking("",0, 0, n,res);
        return res;
    }   
    
    void backtracking(string str, int leftNum, int rightNum, int n, vector<string>& res) {
        if (leftNum == rightNum && leftNum == n) {
            res.push_back(str);
            return;
        } else if (leftNum > n || rightNum > n) {
            return;
        }
        backtracking(str + '(', leftNum + 1, rightNum, n, res);
        if (rightNum < leftNum) backtracking(str + ')', leftNum, rightNum + 1, n, res);
    }
};