#include <cstddef>
#include <fstream>
#include <iterator>
#include <string>
#include <utility>

using namespace std;

/*
    给你一个字符串 s ，请你反转字符串中 单词 的顺序。
    单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
    返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
    注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
*/

class Solution {
public:
    string reverseWords(string s) {
    /* 思路：
            1、消除多余空格
            2、反转整个字符串
            3、以空格分界，再次反转每个单词
    */
    
        // 双指针法在 O(n) 内完成消除多余空格
        // string 的 erase 操作的复杂度本身为 O(n), 此处在循环中使用会导致复杂度达到 O(n^2)
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }

    void removeExtraSpaces(string &s) {
        size_t slow = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                while (i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    void reverse(string &s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};