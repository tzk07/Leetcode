#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

// 思路1: Hash + 排序
// 思路2: 优先队列: 维护一个 大小为 k 的最小堆，堆顶是第 k 大的频率
// 使用 最小堆 的原因: 最小堆的堆顶是第 k 大的频率，所以堆顶就是第 k 大的元素, 方便更新最大频率。
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            // 统计频率
            unordered_map<int, int> freq;
            for (int num : nums) {
                freq[num]++;
            }
            // 维护大小为 k 的最小堆
            /*
            priority_queue<
                pair<int, int>,                    // 1. 存储的元素类型
                vector<pair<int, int>>,            // 2. 底层容器（默认vector, 也可以是deque）
                greater<pair<int, int>>            // 3. 比较器（决定堆的类型）: 最小堆
            > minHeap;
            */
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

            for (auto& [num, count] : freq) {
                // 默认先比较第一个元素, 所以第一个元素是频率, 第二个元素是元素
                minHeap.push({count, num});
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
            vector<int> result;
            while (!minHeap.empty()) {
                result.push_back(minHeap.top().second);
                minHeap.pop();
            }
            return result;
        }
    };