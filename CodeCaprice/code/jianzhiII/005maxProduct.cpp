#include <bits/stdc++.h>
using namespace std;

/* 
定义一个masks数组来记录每个字符串的位掩码，对整个字符串数组进行位运算处理
    可以将每个单词转换为二进制数：有26个英文字母，每个字母分别表示二进制的某一位上的1 
计算号每个单词的二进制表示之后，单词间进行&操作，可以判断单词中是否有相同的字母 （没有一个相同的字母，结果为0；只要有相同的字母，结果就不为0）
 */

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size());
        for (int i = 0; i < words.size(); ++i) {
            for (auto& ch : words[i]) {
                masks[i] |= 1 << (ch - 'a');  // 对应字母上的二进制位为1
            }
        }
        int res = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((masks[i] & masks[j]) == 0) // 两个单词之没有重复元素  考虑到优先级关系，需要加括号
                    res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};

int main() {
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution su;
    su.maxProduct(words);
    return 0;
}