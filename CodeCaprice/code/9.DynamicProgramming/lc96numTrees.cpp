#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // 动规
        vector<int> dp(n + 1);
        dp[0] = 1; // 初始化 空节点也是一棵二叉树，也是一棵二叉搜索树
        for (int i = 1; i <= n; i++) { // 动规数组：计算从1-n节点分别组成的二叉搜索树的数量
            for (int j = 1; j <= i; j++) { // j为头节点的搜索树的数量
                dp[i] += dp[j - 1] * dp[i - j]; // 左子树的二叉搜索树数量 * 右子树二叉搜索树的数量
            }
        }
        return dp[n];
    }
};


int main() {
    return 0;
}