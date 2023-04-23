class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        for (auto& ch : s) {
            if (ch == ' ') cnt++;
        }
        int size = s.size();
        s.resize(size + 2*cnt);
        // 双指针，一个指向原字符串的末尾，一个指向新字符串的末尾
        for (int i = size - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j] = '%';
            } else {
                s[j] = s[i];
            }
        }
        return s;
    }
};