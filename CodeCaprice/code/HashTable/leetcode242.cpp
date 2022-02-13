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