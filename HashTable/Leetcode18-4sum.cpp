#include <algorithm>
#include <vector>
using namespace std;

/*
    给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
        0 <= a, b, c, d < n
        a、b、c 和 d 互不相同
        nums[a] + nums[b] + nums[c] + nums[d] == target
    你可以按 任意顺序 返回答案 。
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 思路和三数之和相同，外层多一层循环，此外去重和剪纸稍有不同
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > target && nums[i] > 0 && target > 0){
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0){
                break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right){
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target){
                        right--;
                    } else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target){
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        // 去重: 找到一个三元组之后，对b 和 c去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;
                        // 找到答案时，双指针同时收缩
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};