#include <algorithm>
#include <vector>
using namespace std;

// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// 双指针求解: 每一次循环, 计算当前柱子能接住的雨水
class Solution {
    public:
        int trap(vector<int>& height) {
            int result = 0;
            int left = 0, right = height.size() - 1;
            int left_max = 0, right_max = 0;
            while (left < right) {
                int water_level = min(left_max, right_max);
                if (height[left] <= water_level) {
                    result += water_level - height[left];
                    left++;
                    continue;
                }
                if (height[right] <= water_level) {
                    result += water_level - height[right];
                    right--;
                    continue;
                }
                left_max = max(left_max, height[left]);
                right_max = max(right_max, height[right]);
            }
            return result;
        }
    };