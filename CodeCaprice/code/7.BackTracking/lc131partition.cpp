class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> res;

        backtracking(0, s, path, res);
        return res;
    }
    void backtracking(int startIndex, string s, vector<string> path, vector<vector<string>>& res) {
        if (startIndex == s.size()) {
            res.push_back(path);
            return;
        }
        string cur = "";
        for (int i = startIndex; i < s.size(); i ++) {
            cur = cur + s[i];
            if (isPalindrome(cur)) {
                path.push_back(cur);
                backtracking(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s) {
        for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
            if (s[left] != s[right]) return false;
        }
        return true;
    }

};