class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size() || s == t) {
            return false;
        }
        int hashTable[26] = {0};
        for (auto& ch : s) {
            hashTable[ch - 'a']++;
        }
        for (auto& ch : t) {
            hashTable[ch - 'a']--;
            // 已经保证了s和t的长度相同，则有小于0的情况出现则不是变位词
            if (hashTable[ch - 'a'] < 0) return false;
        }

        return true;
    }
};