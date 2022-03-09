class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        const string dict[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> res;
        string path;
        backtracing(digits, 0, path, res, dict);
        return res;
    }
    void backtracing(string digits, int index, string path, vector<string>& res, const string dict[]) {
        if (index == digits.size()) {
            res.push_back(path);
            return;
        }
        string letter = dict[digits[index] - '0'];
        for (int i = 0; i < letter.size(); i++) {
            backtracing(digits, index + 1, path + letter[i], res, dict);
        }
    }
};