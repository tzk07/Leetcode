//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    // 方法一：暴力搜索，时间复杂度O(n^2)
    vector<int> twoSum_doubleLoop(vector<int>& nums, int target) {
        for(int i=0; i < nums.size(); i++)
        {
            for(int j=i+1; j < nums.size(); j++)
            {
                if(nums[i]+nums[j]==target)
                    return {i,j};
            }
        }
    }

    // 方法二：哈希表，时间复杂度O(n)
    vector<int> twoSum_hashMap(vector<int>& nums, int target){
        unordered_map<int,int> num_map; // key: 数字，value: 下标
        for(int i=0;i<nums.size();i++)
        {
            int complement=target-nums[i]; // 计算需要找到的补数
            // find()：在哈希表中查找complement，返回迭代器
            // end()：返回哈希表末尾迭代器，表示未找到
            // !=：比较运算符，判断是否找到了complement
            if(num_map.find(complement)!=num_map.end())
            {
                // []运算符：通过key获取value，这里获取complement对应的下标
                return {num_map[complement],i};
            }
            // []运算符：插入或更新键值对，将当前数字作为key，下标作为value
            num_map[nums[i]]=i;
        }
        return {}; // 返回空向量，表示没有找到解
    }
};


int main()
{
    Solution s;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> res=s.twoSum_doubleLoop(nums,target);
    cout << "法1：双循环法\n";
    for(auto i:res)
        cout<< i << "\n";

    res=s.twoSum_hashMap(nums,target);
    cout << "法2：哈希表法\n";
    for(auto i:res)
        cout<< i << "\n";
    return 0;
}