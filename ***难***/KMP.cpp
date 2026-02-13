#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    void GetNext(std::vector<int>& next, std::string s) {
        next.resize(s.size());
        // j 表示前缀末尾，i 表示后缀末尾
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                // 不匹配，回退 j
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                // 匹配，移动 j
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(std::string haystack, std::string needle) {
        // haystack 是主串，needle 是模式串
        if (needle.size() == 0) {
            return 0;
        }
        std::vector<int> next;
        GetNext(next, needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                // 不匹配，回退 j
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                // 匹配，移动 j
                j++;
            }
            if (j == needle.size() - 1) {
                // 匹配成功，返回主串中模式串的起始位置
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
}; 