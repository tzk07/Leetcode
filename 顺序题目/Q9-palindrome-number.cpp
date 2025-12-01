#include <string>
#include <iostream>
using namespace std;

/*
    给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false。
    回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/
class Solution {
public:
    // 思路1：转换为字符串判断，首尾双指针向中间移动判断
    bool isPalindrome_1(int x) {
        string str = to_string(x);
        int left = 0, right = str.size() - 1;
        while(left < right)
        {
            if(str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    // 思路2：不转换为字符串，反转数字后比较
    // 针对肯能出现的溢出问题，使用long long存储反转后的数字，或者只反转一半数字进行比较
    bool isPalindrome_2(int x) {
        // 负数和末尾为0的数（0除外）不是回文
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        
        long long reversed = 0; // 反转后的数字
        long long original = x; // 保存原始数字用于比较

        while(x > 0)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return original == reversed;
    }
};