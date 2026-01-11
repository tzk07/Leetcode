#include<vector>
using namespace std;
/*
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/

class Solution {
public:
    int climbStairs(int n) {
    /*
        定义 dp[i]: 爬到第 i 阶的方法数量
        状态转移方程: 达到第 i 阶: 从 i - 1 阶爬 1 阶; 从 i - 2 阶爬 2 阶
        因此: dp[i] = dp[i - 1] + dp[i - 2]
        边界条件: dp[1] = 1, dp[2] = 2
        目标 dp[n]
    */
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};