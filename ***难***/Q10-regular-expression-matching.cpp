#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
    给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
    '.' 匹配任意单个字符
    '*' 匹配零个或多个前面的那一个元素
    所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。
*/


class Solution {
public:
    // 动态规划：前缀式
    /*
        dp[i][j] 表示 s 的前 i 个字符和 p 的前 j 个字符是否匹配，最终的答案位dp[s.size()][p.size()]
        s 只包含 a-z ; p 只包含 a-z, ., *

        1、基本判断工具：s[i-1] 与 p[j-1] 相等，或 p[j-1]=='.'
        2、初始化：dp[0][0]=true

        状态转移方程：
            (1) p[j-1] != '*'
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
            (2) p[j-1] == '*'
                此时，p[j-2] 是 '*' 前面的字符，记为 x，x不为'*'，则有两种情况：
                1）'*' 代表 0 个 x ： dp[i][j] = dp[i][j-2]
                2）'*' 代表 1 个或多个 x ：
                    此时，s[i-1] 必须与 x 匹配，即 (s[i-1] == x || x == '.')
                    dp[i][j] = dp[i-1][j] && (s[i-1] == x || x == '.')
                综合两种情况：
                dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == x || x == '.'))
    */
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // 空串 vs 含 * 的模式
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }

        auto match = [&](int i, int j) {
            return p[j - 1] == '.' || p[j - 1] == s[i - 1];
        };

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // 0 次：丢 x*
                    dp[i][j] = dp[i][j - 2];
                    // 1+ 次：x 与 s[i-1] 匹配，吃掉一个 s 字符，保留 x*
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    if (match(i, j)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};