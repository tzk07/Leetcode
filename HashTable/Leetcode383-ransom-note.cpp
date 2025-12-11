#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/*
    给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
    如果可以，返回 true ；否则返回 false 。

    magazine 中的每个字符只能在 ransomNote 中使用一次。
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 用一个 unordered_map 记录 magazine 中字符的出现次数, 然后遍历 ransomNote , 判断 unordered_map 是否出现负值
        unordered_map<char, int> map;
        for (char c : magazine){
            map[c]++;
        }
        for (char c : ransomNote){
            map[c]--;
            if (map[c] < 0) return false;
        }
        return true;
    }

    bool canConstruct_array(string ransomNote, string magazine) {
        // 因为字母只有 26 个, 可以直接使用 vector 避免哈希函数的开销
        int record[26] = {0};
        if (ransomNote.size() > magazine.size()) return false;
        for (char c : magazine){
            record[c - 'a']++;
        }
        for (char c : ransomNote){
            record[c - 'a']--;
            if (record[c - 'a'] < 0) return false;
        }
        return true;
    }
};