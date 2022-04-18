#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        while (index1 < version1.size() && index2 < version2.size()) {
            int num1 = 0;
            while (index1 < version1.size() && version1[index1] != '.') {
                num1 = num1 * 10 + (version1[index1++] - '0');
            }
            index1++; // 跳过'.'

            int num2 = 0;
            while (index2 < version2.size() && version2[index2] != '.') {
                num2 = num2 * 10 + (version2[index2++] - '0');
            }
            index2++;

            if (num1 < num2) return -1;
        }
        while (index2 < version2.size()) {  // 如果version1还剩下，那么不管，总比version2大；但如果version2剩下的不是0就比version1大
            int num2 = 0;
            while (index2 < version2.size() && version2[index2] != '.') {
                num2 = num2 * 10 + (version2[index2++] - '0');
            }
            index2++;
            if (num2 != 0) return -1;
        }
        return 0;
    }
};


int main() {
    string version1 = "1.01";
    string version2 = "1.001";
    Solution su;
    su.compareVersion(version1, version2);
    return 0;
}