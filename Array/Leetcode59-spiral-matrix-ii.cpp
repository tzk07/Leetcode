#include <vector>
using namespace std;

/*
    给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int num = 1;
        int target = n * n;

        while (left <= right && top <= bottom) {
            // 1. 从左到右
            for (int col = left; col <= right && num <= target; ++col) {
                matrix[top][col] = num++;
            }
            ++top;

            // 2. 从上到下
            for (int row = top; row <= bottom && num <= target; ++row) {
                matrix[row][right] = num++;
            }
            --right;

            // 3. 从右到左
            for (int col = right; col >= left && num <= target; --col) {
                matrix[bottom][col] = num++;
            }
            --bottom;

            // 4. 从下到上
            for (int row = bottom; row >= top && num <= target; --row) {
                matrix[row][left] = num++;
            }
            ++left;
        }
        return matrix;
    }
};