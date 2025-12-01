/* 
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 法1：合并后排序 - 时间复杂度: O((m+n)log(m+n))
    double findMedianSortedArrays_1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merged.reserve(nums1.size() + nums2.size());
        // insert操作: O(m+n)
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        // sort操作: O((m+n)log(m+n))，这是主导时间复杂度
        sort(merged.begin(), merged.end());

        int totalSize = merged.size();
        if (totalSize % 2 == 1) {
            return merged[totalSize / 2];
        } else {
            return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
        }
    }

    // 法2：归并思想 - 时间复杂度: O(m+n)
    // 利用两个数组已有序的特性，使用双指针找到中位数位置
    double findMedianSortedArrays_2(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        int mid1 = totalSize / 2;
        int mid2 = totalSize / 2 + 1;
        int i = 0, j = 0;
        int count = 0;

        int median1 = 0, median2 = 0;
        // 最多遍历(m+n)/2次，时间复杂度O(m+n)
        while (count < mid2) {
            int temp;
            if(i < nums1.size() && j < nums2.size()) {
                if(nums1[i] < nums2[j]) {
                    temp = nums1[i++];
                } else {
                    temp = nums2[j++];
                }
            } else if(i < nums1.size()) {
                temp = nums1[i++];
            } else {
                temp = nums2[j++];
            }
            count++;
            if(count == mid1) median1 = temp;
            if(count == mid2) median2 = temp;
        }
        if (totalSize % 2 == 1) {
            return median2;
        } else {
            return (median1 + median2) / 2.0;
        }
    }

    // 法3：二分查找 - 时间复杂度: O(log(min(m,n)))
    double findMedianSortedArrays_3(vector<int>& nums1, vector<int>& nums2) {
        
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double res1 = s.findMedianSortedArrays_1(nums1, nums2);
    cout << "中位数为: " << res1 << endl;
    double res2 = s.findMedianSortedArrays_2(nums1, nums2);
    cout << "中位数为: " << res2 << endl;
    return 0;
}