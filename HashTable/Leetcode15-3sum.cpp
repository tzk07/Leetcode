#include <algorithm>
#include <vector>
using namespace std;

/*
    给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

    注意：答案中不可以包含重复的三元组。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 使用 hash 能够在两层 for 循环完成, 但是不好做剪枝操作(对结果三元组的去重)
        // 使用双指针法
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0) return result;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if ((nums[i] + nums[left] + nums[right]) > 0){
                    right--;
                } else if ((nums[i] + nums[left] + nums[right]) < 0)
                {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重: 找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};