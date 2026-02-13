#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std; 

// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
// 用 Hash 表记录字符出现的最后位置, 重复时直接跳到对应位置

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> position;
            int max_length = 0;
            int left = 0, right = 0;
            while (right < s.size()) {
                char currentChar = s[right];
                if (position.find(currentChar) == position.end()) {
                    // 当前字符未出现
                    position[currentChar] = right;
                    max_length = max(max_length, right - left + 1);
                    right++;
                } else {
                    int temp = position[currentChar];
                    left = max(left, temp + 1);
                    position[currentChar] = right;
                    max_length = max(max_length, right - left + 1);
                    right++;
                }
            }
            return max_length;
        }
    };