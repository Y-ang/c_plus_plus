#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memory(s.size(), -1);

        return backtracking(0, memory, s, wordSet);
    }
    bool backtracking(int startIndex, vector<int>& memory, string s, unordered_set<string> wordSet) {
        if (startIndex == s.size()) { //遍历到最后一个元素,上一个循环找到的字串是符合要求的
            return true;
        }
        if (memory[startIndex] != -1) return memory[startIndex];
        for (int i = startIndex; i < s.size(); i++) { // 不断分隔该字串，如果当前循环没找到，返回上一个循环的下标，并且上一个循环中的字串会扩大，继续搜索
            string word = s.substr(startIndex, i - startIndex + 1);
            // 判断word是否满足要求以进行下一层遍历
            if (wordSet.find(word) != wordSet.end() && backtracking(i + 1, memory, s, wordSet)) {
                memory[startIndex] = 1;
                return true;
            }
        }
        memory[startIndex] = 0; // 遍历到最后也没有得到满足条件的字符串
        return false;
    }
};

// 动规
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 将字典中的单词放到set中，方便查找
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        //初始化，若0-当前位置的串在字典中，则把这个位置标为true
        vector<int> dp(s.size(), 0);  // dp[i] 表示0-i的字符串在字典中
        string tmp = "";
        for (int i = 0; i < s.size(); i++) {
            tmp.push_back(s[i]);
            if (wordSet.find(tmp) != wordSet.end()) {
                dp[i] = 1;
            }
        }
        if (dp[s.size() - 1] == 1) return true; 
        // 遍历
        for (int i = 0; i < s.size(); i++) { //找第dp[i]是不是在字典中
            for (int j = 0; j < i; j++) { // 找dp[j] 0-j 在字典中，看j+1 - i是不是在字典中
                if (dp[j] == 1 && dp[i] == 0) {  // 如果dp[i] 0-i单词没有出现在字典里，看是否有满足条件的 j 和 j+1 - i 能让 0 - i 在字典里 
                    dp[i] = wordSet.find(s.substr(j + 1, i - j)) != wordSet.end();
                }
            }
        }
        return dp[s.size() - 1];
    }
};


int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution su;
    su.wordBreak(s, wordDict);

    return 0;
}