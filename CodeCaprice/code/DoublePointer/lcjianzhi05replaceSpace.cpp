class Solution {
public:
    string replaceSpace(string s) {
        // 计算空格数量
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') cnt++;
        }
        // 扩充s，使其能装下%20
        int size = s.size(); // 保存原s的大小
        s.resize(size + 2 * cnt);
        // 设置两个指针，分别指向扩充前和扩充后的下标
        for (int left = size - 1, right = s.size() - 1; left < right; left--) {
            if (s[left] == ' ') {
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
            } else {
                s[right--] = s[left];
            }
        }
        return s;
    }
};