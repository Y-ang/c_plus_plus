/*
    383 赎金信
    给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (int i = 0; i < ransomNote.size(); i++){
            ++record[ransomNote[i]- 'a'];
        }
        for (int i = 0; i < magazine.size(); i++) {
            --record[magazine[i] - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] > 0) {
                return false;
            }
        }
        return true;
    }
};