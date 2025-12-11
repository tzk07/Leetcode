#include <unordered_map>
#include <vector>

using namespace std;

/*
    给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
        0 <= i, j, k, l < n
        nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 题目只需要统计次数而不用输出具体的四元组
        /*
            步骤:
            1、首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
            2、遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
            3、定义int变量count，用来统计 a+b+c+d = 0 出现的次数。
            4、再遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
            5、最后返回统计值 count 就可以了
        */
        unordered_map<int, int> map;
        for (int a : nums1){
            for (int b : nums2){
                map[a + b]++; 
            }
        }
        int count = 0;
        for (int c : nums3){
            for (int d : nums4){
                count += map[0-(c + d)]; 
            }
        }
        return count;
    }
};