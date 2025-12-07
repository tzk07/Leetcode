#include <unordered_set>
using namespace std;

/*
    编写一个算法来判断一个数 n 是不是快乐数。

    「快乐数」 定义为：
        对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
        然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
        如果这个过程 结果为 1，那么这个数就是快乐数。

    如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
*/
class Solution {
public:
    bool isHappy(int n) {
        // 题中提到: 无限循环 —— 通过哈希表判断是否出现重复数字
        int current = n;
        unordered_set<int> has_shown;
        while (!has_shown.count(current)){
            has_shown.insert(current);
            
            int temp = current;
            int next = 0;
            while(temp != 0){
                next += (temp % 10) * (temp % 10);
                temp = temp/10;
            }
            current = next;
            if (current == 1) return true;
        }
        return false;
    }
};