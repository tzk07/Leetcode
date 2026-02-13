#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
// Hash表 记录字符出现次数
// 如何确定窗口移动位置？
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        
        vector<int> pCount(26, 0), sCount(26, 0);
        
        // 初始化p的字符计数和s的第一个窗口
        for (int i = 0; i < p.size(); i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }
        
        if (pCount == sCount) result.push_back(0);
        
        // 滑动窗口
        for (int i = p.size(); i < s.size(); i++) {
            sCount[s[i] - 'a']++;           // 右边加入新字符
            sCount[s[i - p.size()] - 'a']--; // 左边移除旧字符
            
            if (pCount == sCount) result.push_back(i - p.size() + 1);
        }
        
        return result;
    }
    };