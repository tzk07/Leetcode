#include <vector>
#include <unordered_set>
using namespace std;

/*
    给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums_set(nums1.begin(),nums1.end());
        unordered_set<int> result;
        /*
        for (int num : nums1){
            temp.insert(num);
        }
        */

        for (int num : nums2){
            if (nums_set.count(num)){
                result.insert(num);
            }
        }
        return vector<int>(result.begin(),result.end());
    }
};