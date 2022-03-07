#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    string changeString(string& str) {
        int cnt = 0;
        int fast = 1, slow = 0;
        for ( ;fast < str.size(); fast++) {
            cnt++;
            if (str[slow] != str[fast] && cnt > 1){
                str[++slow] = cnt + '0';
                str[++slow] = str[fast];
                cnt = 0;
            } else if (str[slow] != str[fast] && cnt <= 1){
                slow++;
            }
            if (fast == str.size() - 1) {
                if (str[slow] == str[fast]) {
                    str[++slow] = cnt + 1 + '0';
                } else {
                    str[++slow] = '1'; 
                }
            }
        }
        int deleSize = str.size() - slow - 1;
        str.erase(str.begin() + slow + 1, str.end());
        return str;
    }

};

int main() {
    string str= "abbceddddaaaaaaaaaaaakaa";
    Solution su;
    su.changeString(str);
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
    }

    return 0;
}