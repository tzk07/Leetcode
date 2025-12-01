// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
    // 思路：滑动窗口 + 哈希表
    /*
        哈希表 key: 字符，value: 字符对应的下标
        双指针记录字串边界
        右指针右移，字符不重复则加入hash表，更新长度与最大长度
        字符重复，左指针移动到重复字符的下一位，更新长度
    */
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int maxLength = 0;
        // key: 字符，value: 字符对应的下标
        unordered_map<char, int> charIndexMap; 
        while(right < s.size())
        {
            char currentChar = s[right];

            // 表示没有找到重复字符的情况
            if(charIndexMap.find(currentChar) == charIndexMap.end())
            {
                charIndexMap[currentChar] = right;
                maxLength = max(maxLength, right - left +1);
                right++;
            }else{
                int temp = charIndexMap[currentChar];
                // 确保左指针不会回退
                /*
                举个例子：
                字符串："abba"
                当前状态：left = 2, right = 3（指向最后一个'a'）
                哈希表：{a: 0, b: 2} （注意这里'a'的索引还是0）
                当我们遇到最后一个'a'时：
                temp = charIndexMap['a'] = 0
                如果不用max：left = temp + 1 = 1，左指针会从2退回到1
                使用max：left = max(2, 1) =2`，左指针保持不变
                */
                left = max(left , temp + 1);
                charIndexMap[currentChar] = right;
                right++;
                maxLength = max(maxLength, right - left);
            }
        }
        return maxLength;
    }
};

int main(){
    Solution s;
    string str = "abcabcbb";
    int res = s.lengthOfLongestSubstring(str);
    cout << "最长子串的长度为: " << res << endl;
    return 0;
}