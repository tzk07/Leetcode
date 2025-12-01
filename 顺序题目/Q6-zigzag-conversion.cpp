#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 思路1：通过 numRows个vector存储每一行的字符，最后拼接
    // 时间复杂度O(n)，空间复杂度O(n) -- 一次遍历
    string convert_1(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size() ) return s; //特例

        vector<vector<char>> rows(numRows);
        int curRow = 0; // 当前行
        bool goingDown = false; // 方向

        for(int i = 0; i < s.size(); i++)
        {
            rows[curRow].push_back(s[i]);
            // 到达顶端或底端时改变方向
            if(curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string result;
        result.reserve(s.size()); // 预分配空间，避免多次分配
        for(const auto& row : rows)
        {
            result.append(row.begin(), row.end());
        }

        return result;
    }

    // 思路2：周期跳步法，时间 O(n)，不使用多行容器（除输出外空间 O(1)）
    // 难点在数学证明？跳过
    string convert_2(const string &s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size()) return s;
        int n = (int)s.size();
        int cycle = 2 * numRows - 2;
        string result;
        result.reserve(n);

        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < n; j += cycle) {
                result.push_back(s[j]);
                int second = j + cycle - 2 * i; // 对称位置
                if (i != 0 && i != numRows - 1 && second < n) {
                    result.push_back(s[second]);
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    string str = "PAYPALISHIRING";
    int numRows = 3;
    string res = s.convert_1(str, numRows);
    cout << "Z字形变换结果为: " << res << endl;
    return 0;
}