#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int hash[26] = {0};
        for (int i = 0; i < words[0].size(); i++) {
            hash[words[0][i] - 'a']++;
        }

        for (int i = 1; i < words.size(); i++) {
            int hash_[26] = {0};
            string curWord = words[i];
            for (int j = 0; j < curWord.size(); j++) {
                hash_[curWord[j] - 'a']++;
            }
            for (int k = 0; k < 26; k++){
                hash[k] = hash[k] < hash_[k] ? hash[k] : hash_[k]; 
            }
        }
        
        vector<string> res;
        for (int i = 0; i < 26; i++){
            while (hash[i] != 0){
                string s(1, 'a' + i);
                res.push_back(s);
                hash[i]--;
            }
        }
        return res;
    }
};

int main(){
    Solution su;
    vector<string> ve = {"bella","label","roller"};
    su.commonChars(ve);
    return 0;
}