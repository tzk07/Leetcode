#include <algorithm>
#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。

class Solution {
    public:
        // 通过 Hash 的方法能够在 O(n^2) 完成, 但是难做去重操作
        // 采用双指针法解决
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); ++i) {
                // 边界检查
                if (nums[i] > 0) return result;
                // 跳过重复元素
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if (nums[i] + nums[left] + nums[right] > 0) {
                        right--;
                    } else if (nums[i] + nums[left] + nums[right] < 0) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        // 找到了 和为零 的三个元素
                        // 去重逻辑
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;
                        // 找到答案后双指针收缩, 开始下一次循环
                        left++;
                        right--;
                    }
                }
            }
            return result;
        }
    };