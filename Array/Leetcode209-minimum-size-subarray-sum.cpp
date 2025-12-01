#include <cstddef>
#include <vector>
using namespace std;

/*
    给定一个含有 n 个正整数的数组和一个正整数 target 。

    找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

    暴力解法: 遍历数组，每一个元素起始开始向后累加，记录每次是否成功和子数组长度(O(n²))
    滑动窗口: 子数组总和 < target: 右边界++; 子数组总和 >= target: 左边界++(O(n))
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        size_t min_length = nums.size() + 1;
        size_t left = 0;
        size_t right = 0;
        int sum = 0;

        for(right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while(sum >= target)
            {
                min_length = min(min_length, right - left + 1);
                sum -= nums[left];
                left ++;
            }
        }
        min_length = min_length == nums.size() + 1 ? 0:min_length;

        return static_cast<int>(min_length);
    }
};