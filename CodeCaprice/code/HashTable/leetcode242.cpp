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