/*
242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 使用stl map
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for(int i = 0; i < s.size(); i++){
            if(s_map.count(s[i])){
                s_map[s[i]]++;
            }else{
                s_map[s[i]] = 1;
            }
        }
        for(int i = 0; i < t.size(); i++){
           if(t_map.count(t[i])){
               t_map[t[i]]++;
           }else{
               t_map[t[i]] = 1;
           }
        }
        unordered_map<char, int>::iterator it;
        for(it = s_map.begin(); it != s_map.end(); ++it){
            if(it->second != t_map[it->first]){
                return false;
            }
        }

        return true;

    }
};

// 使用一维数组
// 最佳解题方案
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int hashTable[26] = {0};
        for (auto& ch : s) {
            hashTable[ch - 'a']++;
        }
        for (auto& ch : t) {
            hashTable[ch - 'a']--;
            if (hashTable[ch - 'a'] < 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i = 0; i < s.size(); i++){
            record[s[i] - 'a'] += 1;
        }
        for(int i = 0; i < t.size(); i++){
            record[t[i] - 'a'] -= 1;
        }
        for(int i = 0; i < 26; i++){
            if(record[i] != 0){
                return false;
            }
        }
        return true;
    }
};