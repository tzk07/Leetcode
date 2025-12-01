#include <cmath>
#include <vector>
using namespace std;

/*
    给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

    暴力解法：现根据绝对值重新排序，之后再平方，时间复杂度是 O(n + nlogn)
    双指针法：两个指针开始指向原数组两端(可能的平方后最大值)，不断向中间合拢(最小的平方值)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int ptr = right;

        while(left <= right)
        {
            // if(abs(nums[left]) >= nums[right])
            if (nums[left]*nums[left] >= nums[right]*nums[right])
            {
                squares[ptr] = nums[left] * nums[left];
                ptr --;
                left ++;
            } // else if (abs(nums[left]) < nums[right])
            else if (nums[left]*nums[left] < nums[right]*nums[right])
            {
                squares[ptr] = nums[right] * nums[right];
                ptr --;
                right --;
            }
        }

        return squares;
    }
};