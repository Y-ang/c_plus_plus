#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串 
     * @param version2 string字符串 
     * @return int整型
     */
    int compare(string version1, string version2) {
        // write code here
        if (version1 == version2) return 0;
        int start1 = 0;
        int start2 = 0;
        while (start1 < version1.size() || start2 < version2.size()) {
            uint64_t num1 = 0;
            while (start1 < version1.size() && version1[start1] != '.') {
                num1 = num1 * 10 + (version1[start1++] - '0');
            }
            start1++; // 跳过'.'
            uint64_t num2 = 0;
            while (start2 < version2.size() && version2[start2] != '.') {
                num2 = num2 * 10 + (version2[start2++] - '0');
            }
            start2++; // 跳过'.'

            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
        }
        return 0;
    }
};

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 比较版本号
//      * @param version1 string字符串 
//      * @param version2 string字符串 
//      * @return int整型
//      */
//     int compare(string version1, string version2) {
//         // write code here
//         if (version1 == version2) return 0;
//         int start1 = 0;
//         int start2 = 0;
//         while (start1 < version1.size() && start2 < version2.size()) {
            
//             int num1 = getNum(start1, version1);

//             int num2 = getNum(start2, version2);

//             if (num1 > num2) return 1;
//             else if (num1 < num2) return -1;
//             else continue;
//         }
//         while (start1 < version1.size()) {
//             int num = getNum(start1, version1);
//             if (num != 0) return 1;
//         } 
//         while (start2 < version2.size()) {
//             int num = getNum(start2, version2);
//             if (num != 0) return -1;
//         }
//         return 0;
//     }
//     int getNum(int& start, string version) {
//         int index = start;
//         while (start < version.size() && version[start] != '.') {
//             start++;
//         }
//         string s = version.substr(index, start - index);  // 版本字符串
//         start++; // 跳过 '.'

//         int i = 0;
//         while (i < s.size() && s[i] == '0') {
//             i++;
//         }
//         if (i >= s.size()) return 0;  // 该字符串全为0
//         s = s.substr(i, s.size() - i);   // 去调头部0的版本字符串

//         return stoi(s);
//     }
// };

int main() {
    Solution su;
    su.compare("1.0.1","1");

    return 0;
}