#include <unordered_map>
#include <vector>
#include <string>
#include <array>

using namespace std;
// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> result;
            // 法1: 先对字符串排序, 将排序后的作为 key, 通过 Hash 查找 —— O(N × K log K)
            // 法2: 只包含小写字母的串, 可以统计字母出现次数, 将字符频率直接作为 HashKey —— O(N × K)
            unordered_map<string, vector<string>> groups;
            for (string s : strs) {
                array<int, 26> count = {};
                for (char c : s) {
                    count[c - 'a']++;
                }

                // 将计数数组转为字符串作为key
                // 例如：[1,0,0,0,1,0...] -> "#1#0#0#0#1#0..."
                string key;
                for (int num : count) {
                    key += '#' + to_string(num);
                }
                groups[key].push_back(s);
            }
            for (auto & pair : groups) {
                result.push_back(pair.second);
            }
            return result;
        }
    };