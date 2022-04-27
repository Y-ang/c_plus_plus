#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP)) return "IPv4";
        else if (isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }

    bool isIPv4(string queryIP) {
        vector<string> ip;
        split(queryIP, ip, '.');
        if (ip.size() != 4) return false;  // ip地址不是四段
        for (string str : ip) {
            if (str.size() == 0 || str.size() > 3 || (str.size() > 1 && str[0] == '0'))  // 该段数字为空、长度大于3、有前导零
                return false;
            for (auto& ch : str) {   // 字符中出现非数字的特殊字符
                if (!isdigit(ch)) return false;
            }
            if (stoi(str) < 0 || stoi(str) > 255) return false; // 数字非法
        }
        return true;
    }

    bool isIPv6(string queryIP) {
        vector<string> ip;
        split(queryIP, ip, ':');
        if (ip.size() != 8) return false; // ip地址不是8段
        for (auto& str : ip) { 
            if (str.size() == 0 || str.size() > 4) return false;
            for (auto& ch : str) {  // 不是数字 不是a-f 不是A-F
                if (!(isdigit(ch) || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))) return false;
            }
        }
        return true;
    }

    void split(string str, vector<string>& ip, char del) {
        stringstream ss(str);
        string tmp;
        while (getline(ss, tmp, del)) {
            ip.push_back(tmp);
        }
        if (str.size() > 0 && str.back() == del) ip.push_back(""); // 最后一个字符为分隔符，"2001:0db8:85a3:0:0:8A2E:0370:7334:"
    }
};

int main () {
    string ip = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
    Solution su;
    su.validIPAddress(ip);
    return 0;
}