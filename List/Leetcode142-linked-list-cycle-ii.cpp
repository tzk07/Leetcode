/*
    给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

    如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

    不允许修改 链表。
*/

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 难点1：如何判断有环
        // 解法：可以使用快慢指针法，分别定义 fast 和 slow 指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。
        // 难点2：找到环的入口(算是一个数学问题)
        // 参数说明：
        //     x: 链表头节点到环入口的距离
        //     y: 入口节点到相遇节点的距离
        //     z: 相遇节点回到换入口的距离
        // 解法：相遇时： slow指针走过的节点数为: x + y， fast指针走过的节点数：x + y + n (y + z)，n为fast指针在环内走了n圈才遇到slow指针， （y+z）为 一圈内节点的个数A。
        // 因为fast指针是一步走两个节点，slow指针一步走一个节点，所以 fast指针走过的节点数 = slow指针走过的节点数 * 2：(x + y) * 2 = x + y + n (y + z)
        // 关键等式: x = (n−1)*(y + z) + z <=> fast 和 slow 相遇后，从 头结点 和 相遇点 同时派出一个指针向后移动，二者会在 环入口 相遇: 头结点开始的移动 x, 相遇点的移动 (n−1)*(y + z) + z, (n−1)*(y + z) 是 (n-1) 个环长度, z 为 相遇点到 环入口 的距离
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从 head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return nullptr;
    }
};