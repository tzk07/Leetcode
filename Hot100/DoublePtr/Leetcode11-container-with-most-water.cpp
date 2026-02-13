#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;

// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 返回容器可以储存的最大水量。

class Solution {
    public:
        int maxArea(vector<int>& height) {
            size_t left = 0, right = height.size() - 1;
            int maxArea = 0;
            while (left < right) {
                int h = min(height[left], height[right]);
                int area = h * (right - left);
                maxArea = max(maxArea, area);
                if (height[left] > height[right]) {
                    right--;
                } else {
                    left++;
                }
            }
            return maxArea;
        }
    };