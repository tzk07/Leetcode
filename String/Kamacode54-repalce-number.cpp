#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

/*
    给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。 
    例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
*/

int main() {
    // 辅助空间: 新建一个字符串, 一次遍历完成
    // 不用辅助空间: 先将原字符串扩容, 然后从尾部的数字开始替换
    /*
        很多数组填充类的问题，其做法都是先预先给数组扩容带填充后的大小，然后在从后向前进行操作。
        这么做有两个好处：
            不用申请新数组。
            从后向前填充元素，避免了从前向后填充元素时，每次添加元素都要将添加元素之后的所有元素向后移动的问题。
    */
    string s;
    while (cin >> s) {
        int sOldIndex = s.size() - 1;
        int count = 0; // 记录数字个数
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9'){
                count ++;
            }
        }
        s.resize(s.size() + 5 * count);
        int sNewIndex = s.size() - 1;

        while (sOldIndex >= 0) {
            if (s[sOldIndex] >= '0' && s[sOldIndex] <= '9') {
                s[sNewIndex--] = 'r';
                s[sNewIndex--] = 'e';
                s[sNewIndex--] = 'b';
                s[sNewIndex--] = 'm';
                s[sNewIndex--] = 'u';
                s[sNewIndex--] = 'n';
            } else {
                s[sNewIndex--] = s[sOldIndex];
            }
            sOldIndex--;
        }
        cout << s << endl;
    }
}