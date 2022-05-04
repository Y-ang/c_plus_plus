

/* 
给定两个字符串 s 和 t ，判断它们是否是同构的。
输入：s = "egg", t = "add"
输出：true

输入：s = "foo", t = "bar"
输出：false
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        // 实现双射,记录两个字符串当前字符前一次出现时的下标，如果不同就返回false
        vector<int> preIndexOfs(256);   // char占一个字节，一共256个不同的字符
        vector<int> preIndexOft(256);
        for (int i = 0; i < s.size(); ++i) {
            if (preIndexOfs[s[i]] != preIndexOft[t[i]]) {
                return false;
            }
            preIndexOfs[s[i]] = preIndexOft[t[i]] = i + 1;   // 使用i + 1来更新下标而不是i, 是因为向量初始时被初始化为0，0的存在会出现误导 如：bab  car
        }
        return true;
    }
};