#include <array>
#include <vector>
#include <algorithm>
using namespace std;

/*
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

    假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：

    更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
    返回 k。
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        /*
            std::remove(first, last, val): 在区间 [first, last) 内“移除”所有等于 value 的元素
            它不真的删除容器元素，它只是稳定地（保持其余元素相对次序）把“不等于 value 的元素”向前搬运覆盖那些要删的元素。
            执行后，对vector而言，得到的前半段为目标数据，后半段为残留的脏数据
            返回值: 一个迭代器 new_end，指向“新逻辑序列”的末尾（即有效元素的下一个位置）

            vector.erase(first, last): 把区间 [first, last) 的元素从容器里真正删除，并把后面的元素整体左移填补空隙
            调用后: size() 变小；capacity() 一般不变（不会自动收缩容量）

            拆开来写：
            auto new_end = std::remove(nums.begin(), nums.end(), val);
            nums.erase(new_end, nums.end());
        */
        return nums.size();
    }

    int removeElement2(vector<int>& nums, int val){
        // 不使用 remove 和 erase，采用双指针法
        // 双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。
        size_t fastIndex; // 遍历数组的指针
        size_t slowIndex = 0; // 记录修改位置的指针

        for(fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (val != nums[fastIndex])
            {
                nums[slowIndex] = nums[fastIndex];
                slowIndex ++;
            }
        }

        return slowIndex;
    }
};