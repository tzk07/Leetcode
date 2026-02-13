#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
// 给定一个未排序的整数数组 nums, 找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end());
            int longest = 0;

            for (int num : numSet) {
                // 只从序列起点开始, 跳过不是起点的元素
                if (numSet.find(num - 1) == numSet.end()) {
                    int currentNum = num;
                    int currentLength = 1;

                    // 向后枚举
                    while (numSet.find(currentNum + 1) != numSet.end()) {
                        currentNum++;
                        currentLength++;
                    }

                    longest = max(currentLength, longest);
                }
            }
            return longest;
        }
    };