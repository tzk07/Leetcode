#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int n = s.size();
        unordered_map<char, int> roman = {{'I', 1},{'V', 5},{'X', 10},{'L',50},{'C', 100},{'D', 500},{'M', 1000}};

        for (int i = 0; i < n - 1; ++i) {
            int cur = roman[s[i]];
            int next = roman[s[i + 1]];
            
            if (cur < next) {
                result -= cur;  // 小值在大值前：减去（如 IV=4）
            } else {
                result += cur;  // 正常情况：加上
            }
        }
        result += roman[s[n - 1]];
        return result;
    }
};