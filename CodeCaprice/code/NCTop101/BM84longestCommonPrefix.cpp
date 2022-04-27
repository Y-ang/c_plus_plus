class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            res = commonPrefix(res, strs[i]);
        }
        return res;
    }
    
    string commonPrefix(string str1, string str2) {
        int i = 0;
        for ( ; i < str1.size() && i < str2.size(); i++) {
            if (str1[i] != str2[i]) {
                break;
            }
        }
        return str1.substr(0, i);
    }
};