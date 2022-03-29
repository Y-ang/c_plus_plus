#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(t.size() + 1, vector<long long>(s.size() + 1, 0));
        // vector<vector<unsigned long long>> dp(t.size() + 1, vector<unsigned long long>(s.size() + 1, 0));    //uint64_t 是 unsigned long long 的别名，0-2^64-1
        for (int i = 0; i < s.size() +1; i++) dp[0][i] = 1;
        for (int i = 1; i < t.size() + 1; i++) {
            for (int j = 1; j < s.size() + 1; j++) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]; //  t的i-1和s的j-1 与 t的i和s的j - 1 
                } else {
                    dp[i][j] = dp[i][j - 1];   // 不相等就等于前面一个
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};

int main() {
    string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    Solution su;
    su.numDistinct(s, t);

    return 0;
}