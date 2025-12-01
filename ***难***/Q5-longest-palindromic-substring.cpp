#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 思路1：中心扩展法，时间复杂度O(n^2)，空间复杂度O(1)
    /*
        从头开始遍历字符串，每个字符作为中心向两边扩展
        注意奇偶：
            奇数串：以字符i为中心
            偶数串：以字符i和i+1为中心
    */
    string longestPalindrome_1(string s) {
        int start = 0, end = 0; // 记录最长回文子串的起始和结束位置
        int maxLength = 0; // 记录最长回文子串的长度

        for(int i = 0; i < s.size(); i++)
        {
            // 奇数串
            int len = 0;
            int left = i, right = i;
            // 扩展时同时检查边界和字符相等，字符不相等时退出循环，避免无限循环
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                len = right - left + 1;
                if(len > maxLength)
                {
                    maxLength = len;
                    start = left;
                    end = right;
                }
                left--;
                right++;
            }

            // 偶数串
            len = 0;
            left = i, right = i + 1;
            // 偶数回文的扩展，同样在条件中检查字符相等
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                len = right - left + 1;
                if(len > maxLength)
                {
                    maxLength = len;
                    start = left;
                    end = right;
                }
                left--;
                right++;
            }
        }

        cout << "最长回文子串的为: " << s.substr(start, maxLength) << endl;
        cout << "最长回文子串的长度为: " << maxLength << endl;
        return s.substr(start, maxLength);
    }

    // 思路2：Manacher 算法，时间复杂度O(n)，空间复杂度O(n)
    /*
        1. 预处理字符串：在每个字符之间插入特殊字符（如#），并在开头和结尾添加边界字符（如^和$），以处理奇偶长度的回文。
        2. 使用一个数组P来记录以每个字符为中心的最长回文半径。
        3. 使用两个变量C和R来跟踪当前已知的最右回文子串的中心和右边界。
        4. 对于每个字符i，计算其对称位置i'，并根据i'的P值初始化P[i]。
        5. 尝试扩展以i为中心的回文，并更新C和R。
        6. 最后，从P数组中找到最大值及其对应的中心位置，计算出最长回文子串在原始字符串中的起始位置和长度。
    */
    string Manacher(string s) {
        // 预处理字符串
        string T = "^"; // 左边界
        for (char c : s) {
            T += "#" + string(1, c);
        }
        T += "#$"; // 右边界

        int n = T.size();
        int maxLength = 0; // 记录最长回文子串的长度
        int centerIndex = 0; // 记录最长回文子串的中心位置
        vector<int> P(n, 0); // P[i]表示以T[i]
        int C = 0, R = 0; // 当前回文子串的中心和右边界

        for (int i = 1; i < n - 1; i++)
        {
            int mirr = 2 * C  - i;
            if(i < R)
                P[i] = min(R - i, P[mirr]);

            // 尝试扩展回文
            while(T[i + P[i] + 1] == T[i - P[i] - 1])
                P[i]++;
            
            // 更新中心、扩展边界
            if(P[i] + i > R)
            {
                C = i;
                R = P[i] + i;
            }
            // 记录最长回文子串
            if(P[i] > maxLength)
            {
                centerIndex = i;
                maxLength = P[i];
            }
        }

        int start = (centerIndex - maxLength) / 2; // 计算原始字符串中的起始位置
        cout << "最长回文子串的为: " << s.substr(start, maxLength) << endl;
        cout << "最长回文子串的长度为: " << maxLength << endl;
        return s.substr(start, maxLength);
    }
};

int main(){
    Solution s;
    string str = "babad";
    string res = s.Manacher(str);
    cout << "最长回文子串为: " << res << endl;
    return 0;
}