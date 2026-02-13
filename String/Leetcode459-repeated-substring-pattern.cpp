#include<string>
#include<vector>
using namespace std;

// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
// 思路: 如果一个字符串 s 由一个子串重复多次构成, 那 s + s 的中间部分一定包含 s。
class Solution {
    public:
        bool repeatedSubstringPattern(string s) {
            string new_s = s + s;
            // 删除第一个和最后一个字符
            new_s.erase(new_s.begin());
            new_s.erase(new_s.end() - 1);
            return new_s.find(s) != string::npos;
        }
    };