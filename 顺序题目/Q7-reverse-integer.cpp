#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    /*
    给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
    如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
    */
    // 思路：栈实现
    int reverse_1(int x) {
        bool isNegative = x < 0; // 记录符号
        long long absX = abs((long long)x); // 取绝对值，
        long long reversed = 0; // 反转后的数字

        stack<int> digist;
        // 逐位入栈（从低到高）
        while(absX > 0)
        {
            digist.push(absX % 10);
            absX /= 10;
        }
        // 逐位出栈，构建反转数字
        long long place = 1; // 位数
        while(!digist.empty())
        {
            reversed += digist.top() * place;
            digist.pop();
            place *= 10;
        }

        if(isNegative) reversed = -reversed; // 恢复符号
        // 检查是否溢出32位整数范围
        if(reversed < INT_MIN || reversed > INT_MAX)
            return 0;
        return (int)reversed;
    }

    // 思路2：其实不需要用栈
    int reverse_2(int x){
        bool isNegative = x < 0;
        long long absX = abs((long long)x);
        long long reversed = 0;
        while(absX > 0)
        {
            reversed = reversed * 10 + absX % 10;
            absX /= 10;
        }
        if(isNegative) reversed = -reversed;
        if(reversed < INT_MIN || reversed > INT_MAX)
            return 0;
        return (int)reversed;
    }
};