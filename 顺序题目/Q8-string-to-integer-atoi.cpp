#include <string>
#include <iostream>
#include <climits>
#include <cctype>
using namespace std;
/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。

函数 myAtoi(string s) 的算法如下：

空格：读入字符串并丢弃无用的前导空格（" "）

符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。

转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。

舍入：如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −2^31 的整数应该被舍入为 −2^31 ，大于 2^31 − 1 的整数应该被舍入为 2^31 − 1 。
*/

class Solution {
public:
    // 注：不要把所有的工作放在一个循环里进行，顺序是：跳过空格 -> 处理符号 -> 转换数字
    // 如果想用一个循环解决问题，可能需要引入两个Boolean变量，确认当前的阶段，这样会导致每一次循环都要检查两个变量，反而更复杂
    // 时间复杂度O(n)，空间复杂度O(1)
    int myAtoi(string s) {
        int result = 0; // 最终结果
        bool isNegative = false; // 记录符号
        int i = 0;
        
        // 跳过前导空格
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        
        // 处理符号
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            isNegative = s[i] == '-';
            i++;
        }
        
        // 转换数字
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0'; // 字符转数字
            // 检查是否会溢出
            if (result > (INT_MAX - digit) / 10) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            result = result * 10 + digit;
            i++;
        }

        return isNegative ? -result : result; // 恢复符号
    }
};