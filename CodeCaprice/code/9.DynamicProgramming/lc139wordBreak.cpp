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


int main() {
    string s = "leetcode2";
    vector<string> wordDict = {"leet", "code"};
    Solution su;
    su.wordBreak(s, wordDict);

    return 0;
}