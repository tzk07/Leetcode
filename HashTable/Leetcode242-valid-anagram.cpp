#include <string>
#include <vector>
using namespace std;

/*
    给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 用一个长度为26的 数组 记录每个字母出现的次数
        if (s.length() != t.length()) return false;
        
        vector<int> count(26, 0);
        
        // 同时处理两个字符串
        for (int i = 0; i < s.length(); ++i) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }
        
        // 检查是否有非零
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) return false;
        }
        
        return true;
    }
};