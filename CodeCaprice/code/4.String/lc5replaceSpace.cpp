#include<bits/stdc++.h>
using namespace std;


// // 有辅助string，内存消耗大
// class Solution {
// public:
//     string replaceSpace(string s) {
//         string res;
//         for (int i = 0; i < s.size(); i++){
//             if (s[i] == ' '){
//                 res.push_back('%');
//                 res.push_back('2');
//                 res.push_back('10');

//             } else {
//                 res.push_back(s[i]);
//             }
//         }
//         return res;
//     }
// };

// 没有辅助内存开销
class Solution {
public:
    string replaceSpace(string s) {
        int spaceCnt = 0;
        int sOldSize = s.size();
        for (int i = 0; i < sOldSize; i++) {
            if (s[i] == ' '){
                spaceCnt++;
            }
        }
        int sNewSize = sOldSize + spaceCnt * 2;
        s.resize(sNewSize);
        for (int i = sNewSize - 1, j = sOldSize - 1; j >= 0; i--, j--) {
            if (s[j] == ' ') {
                s[i--] = '0';
                s[i--] = '2';
                s[i] = '%';
            } else {
                s[i] = s[j];
            }
        }
        return s;
    }
};

int main() {
    Solution su;
    string s = su.replaceSpace("  ");
    return 0;
}