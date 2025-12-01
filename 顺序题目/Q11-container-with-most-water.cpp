#include <vector>
#include <iostream>
using namespace std;
/*
    给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
    返回容器可以储存的最大水量。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            max_area = max(max_area, h * w);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_area;
    }
};